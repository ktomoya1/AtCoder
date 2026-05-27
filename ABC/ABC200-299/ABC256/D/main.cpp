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

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Sを最小個数の右半開区間の和集合で表示する
    // 未満と以上は繋げられる
    // 一番小さいものから進めたい->sort
    int N;
    cin >> N;
    vector<pair<int, int>> LR(N);
    rep(i, N) cin >> LR[i].first >> LR[i].second;
    sort(LR.begin(), LR.end());

    // 範囲内だったら継続して広げる、範囲外だったら、lとrを変更する
    // 範囲内：L: L >= l && L <= r、これなら伸ばせる
    // 伸ばすとき、r = max(r, R);
    // 範囲外：L > rの時、元のlとrを出力、lとrを変更
    // for文を抜けた後にlとrを出力
    int l = LR[0].first, r = LR[0].second;
    for (int i = 1; i < N; i++) {
        auto [L, R] = LR[i];
        // 範囲内
        if (L <= r) {
            r = max(r, R);
        } else {
            // 範囲外
            cout << l << ' ' << r << "\n";
            l = L;
            r = R;
        }
    }
    cout << l << ' ' << r << "\n";
    return 0;
}
