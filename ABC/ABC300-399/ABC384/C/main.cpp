#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>
#include <ranges>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 31行出力せよ。からABCDEの2^5から0を引いた31通り（全部）を出力する必要がある
    // i番目に高い得点を獲得した参加者の名前を出力せよ。辞書順で小さな名前を持つ参加者を先に出力せよ。
    // からスコアと参加者の得点した文字列が必要だと思った。
    // 高い得点順にソートする必要がある。同じ得点なら辞書順で小さい名前を持つ参加者を先に出力する
    array<int, 5> point{};
    for (auto&& p : point)
        cin >> p;
    vector<pair<int, string>> standings;
    for (int bit = 1; bit < 32; ++bit) {
        int score = 0;
        string name = "";
        for (int digit = 0; digit < 5; ++digit) {
            if (bit & (1 << digit)) {
                score += point[digit];
                name += "ABCDE"[digit];
            }
        }
        standings.emplace_back(score, name);
    }
    // ソート
    ranges::sort(standings, less{}, &pair<int, string>::second);
    ranges::stable_sort(standings, greater{}, &pair<int, string>::first);
    for (const auto& name : standings | views::values)
        cout << name << "\n";
    return 0;
}
