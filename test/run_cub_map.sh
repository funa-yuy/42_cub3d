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

# .cub ファイルを再帰的に探して実行
find "$TARGET_DIR" -type f -name "*.cub" | sort | while read -r filepath; do
    echo -e "\033[0;32m実行中: ./cub3d \"$filepath\"\033[0m"
    ./cub3d "$filepath"
done
