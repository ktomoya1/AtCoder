#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// WAの原因：面積順ソートより昇順ソートを使うべきだった. xソート+miny管理が正解。
// 条件の言い換えが不完全だった->パターン未認識
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 点1から点NまでのN個の点をどれも含まないようなiの個数
    // iが内部に含まれる->Xj<XiかつYj<Yiとなる点jが存在すること
    // 順番は関係ないのでペアをソートしたいが、Xが小さくてもYが大きいものがある
    // そこで面積順（小さい順から）に見ていくことにする
    // 最初に出てきた数字が一番小さい数字、これより大きい数字はカウントしない

    int n;
    cin >> n;
    vector<pair<ll, ll>> xy(n);
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }

    // auto cmp = [&](pair<ll, ll> a, pair<ll, ll> b) -> bool {
    //     return a.first * a.second < b.first * b.second;
    // };
    sort(xy.begin(), xy.end());

    ll miny = xy[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        auto [_, y] = xy[i];
        if (y < miny) {
            ans++;
            miny = y;
        }
    }
    cout << ans << "\n";
    return 0;
}
