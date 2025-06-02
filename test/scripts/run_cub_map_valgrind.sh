#!/bin/bash

# 引数がない場合、使い方を表示して終了
if [ $# -ne 1 ]; then
    echo "使い方: $0 <ディレクトリ名>"
    echo "例:    $0 map"
    echo "       $0 map/test"
    exit 1
fi

TARGET_DIR="$1"

# ディレクトリが存在するか確認
if [ ! -d "$TARGET_DIR" ]; then
    echo "エラー: ディレクトリ '$TARGET_DIR' が存在しません"
    exit 1
fi

# カウンターの初期化
total_maps=0
success_maps=0
error_maps=()
valgrind_error_maps=()

# 一時ファイルの作成
temp_file=$(mktemp)
valgrind_temp_file=$(mktemp)

# .cub ファイルを再帰的に探して実行
while IFS= read -r filepath; do
    echo -e "\033[0;32m実行中: ./cub3d \"$filepath\"\033[0m"

    valgrind_output=$(mktemp)
    valgrind --leak-check=full ./cub3d "$filepath" &> "$valgrind_output"
    exit_code=$?

    # ValgrindのERROR SUMMARY行を抽出して表示
    error_summary=$(grep "ERROR SUMMARY" "$valgrind_output" | tail -n 1)
    echo "$error_summary"

    # Valgrind上のエラーがあるか確認
    if ! echo "$error_summary" | grep -q "0 errors"; then
        valgrind_error_maps+=("$filepath")
    fi

    ((total_maps++))

    if [ $exit_code -eq 0 ]; then
        ((success_maps++))
    else
        echo "$filepath" >> "$temp_file"
    fi

    rm -f "$valgrind_output"
done < <(find "$TARGET_DIR" -type f -name "*" | sort)

# エラーマップの読み込み
if [ -s "$temp_file" ]; then
    while IFS= read -r line; do
        error_maps+=("$line")
    done < "$temp_file"
fi

# 一時ファイルの削除
rm -f "$temp_file" "$valgrind_temp_file"

# 結果の表示
echo -e "\n\033[0;34m=== テスト結果 ===\033[0m"
echo -e "正常終了したマップ: $success_maps/$total_maps"

if [ ${#error_maps[@]} -gt 0 ]; then
    echo -e "\n\033[0;31mERROR_MAP:\033[0m"
    for map in "${error_maps[@]}"; do
        echo -e "\033[0;31m- $map\033[0m"
    done
fi

if [ ${#valgrind_error_maps[@]} -gt 0 ]; then
    echo -e "\n\033[0;33mVALGRIND_ERROR_MAP:\033[0m"
    for map in "${valgrind_error_maps[@]}"; do
        echo -e "\033[0;33m- $map\033[0m"
    done
fi
