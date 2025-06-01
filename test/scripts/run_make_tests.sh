#!/bin/bash

# 引数がない場合
if [ $# -eq 0 ]; then
    echo "使い方: $0 <ファイルパス...>"
    echo "例:    $0 test/unit-tests/load/init_test*.c"
    echo "       $0 test/unit-tests/load/init_test01.c test/unit-tests/load/init_test02.c"
    exit 1
fi

# プロジェクトルートに移動
cd "$(dirname "$0")/../.."

total_tests=0
success_tests=0
error_files=()
temp_file=$(mktemp)

echo -e "\033[0;34m=== Cテストファイル実行スクリプト ===\033[0m"
echo -e "対象ファイル数: $#"
echo ""

# すべての引数を個別ファイルとして処理
for filepath in "$@"; do
    if [ ! -f "$filepath" ]; then
        echo -e "\033[0;31mエラー: ファイル '$filepath' が存在しません\033[0m"
        continue
    fi

    filename=$(basename "$filepath")
    ((total_tests++))

    echo -n -e "\033[0;32m[$total_tests/$#] $filename\033[0m ... "

    if make test "$filepath" >/dev/null 2>&1; then
        ((success_tests++))
        echo -e "\033[0;32m✓ OK\033[0m"
    else
        echo "$filepath" >> "$temp_file"
        echo -e "\033[0;31m✗ ERROR\033[0m"
    fi
done

# 結果処理
if [ -s "$temp_file" ]; then
    while IFS= read -r line; do
        error_files+=("$line")
    done < "$temp_file"
fi

rm -f "$temp_file"
make test-clean >/dev/null 2>&1

echo ""
echo -e "\033[0;34m=== テスト結果 ===\033[0m"
echo -e "正常終了したテスト: \033[0;32m$success_tests\033[0m/\033[0;34m$total_tests\033[0m"

if [ ${#error_files[@]} -gt 0 ]; then
    echo -e "\n\033[0;31mERROR_FILES:\033[0m"
    for file in "${error_files[@]}"; do
        echo -e "\033[0;31m- $(basename "$file")\033[0m"
    done
fi
