# AtCoder Solutions

私がAtCoderで解いた問題の解答コードを管理しているリポジトリです。
This repository contains my solutions for AtCoder contests.

## Languages
* C++

## Note on Code Style (重要)
こちらは**競技プログラミング用**のコードです。
実務のコードとは異なり、以下の点を優先して記述しています。
* **優先事項:** 可読性や保守性よりも、コンテスト中の「実装速度」と「実行速度」を最優先しています。
* **コーディングスタイル:** マクロの多用、短縮された変数名、`bits/stdc++.h`の使用など、競プロ特有の書き方を含みます。

These codes are written specifically for **Competitive Programming**.
Please note the following:
* **Priority:** Implementation speed and execution performance > Readability/Maintainability.
* **Style:** Usage of macros, short variable names, and `using namespace std;` are intentional for contest constraints.

## 👤 Profile
* **AtCoder:** [ktomoya](https://atcoder.jp/users/ktomoya)

## 環境・使い方
* 新規問題: `scripts/new.sh abc468 c` → `ABC/ABC400-499/ABC468/C/` に `template/` をコピーし、`oj d` でサンプルを `test/` に取得
* テスト: 問題ディレクトリで `make test`（`g++ -std=c++23 -O2` でビルド → `oj t`）
* 必要ツール: g++ / [online-judge-tools](https://github.com/online-judge-tools/oj) / [ACL](https://github.com/atcoder/ac-library)（任意）
* Claude Codeクラウドでは環境「atcoder」を選ぶと、atcoder.jp への接続とツール導入が自動で済む
