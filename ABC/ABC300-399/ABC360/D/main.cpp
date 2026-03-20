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

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // n: アリの数
    // t: 時間
    // s: 0と1からなる長さnの文字列, 0は負の方向、1は正の方向
    // xi: アリの座標
    // タグ：二分探索、相対速度
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> x(n);
    string s;
    cin >> s;
    rep(i, n) cin >> x[i];

    vector<ll> left_ants, right_ants;
    rep(i, n) {
        if (s[i] == '0') left_ants.push_back(x[i]);
        else right_ants.push_back(x[i]);
    }
    sort(left_ants.begin(), left_ants.end());

    ll ans = 0;
    for (auto x : right_ants) {
        auto lo = upper_bound(left_ants.begin(), left_ants.end(), x);
        auto hi = upper_bound(left_ants.begin(), left_ants.end(), x + 2 * t);
        ans += hi - lo;
    }
    cout << ans << "\n";
    return 0;
}
