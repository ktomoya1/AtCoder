#!/usr/bin/env bash
# 使い方: scripts/new.sh abc468 c   → ABC/ABC400-499/ABC468/C を作成しサンプル取得
set -euo pipefail
[ $# -eq 2 ] || { echo "usage: $0 <contest> <task>  (例: $0 abc468 c)" >&2; exit 1; }
root=$(cd "$(dirname "$0")/.." && pwd)
contest=${1,,}; task=${2,,}
num=${contest#abc}
[[ $contest == abc* && $num =~ ^[0-9]+$ ]] || { echo "ABCのみ対応: $contest" >&2; exit 1; }
lo=$(( 10#$num / 100 * 100 ))
dir="$root/ABC/ABC${lo}-$((lo + 99))/ABC${num}/${task^^}"
mkdir -p "$dir"
[ -e "$dir/main.cpp" ] || cp "$root/template/main.cpp" "$dir/"
[ -e "$dir/Makefile" ] || cp "$root/template/Makefile" "$dir/"
cd "$dir"
[ -d test ] || oj d "https://atcoder.jp/contests/${contest}/tasks/${contest}_${task}" || echo "サンプル取得失敗（ネットワーク/ログインを確認）" >&2
echo "$dir"
