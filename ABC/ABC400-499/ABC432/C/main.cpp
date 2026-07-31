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

// 解説AC
// 重量を固定した時にXの個数xiとYの個数yiの連立方程式を立てられることに気づかなかった
// 大あめを小あめにしたとき、重さの和はY-X減る
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll minw = a[0] * y;
    ll ans = 0;
    rep(i, n) {
        ll w = a[i] * y;
        ll dif = w - minw;
        if (dif % (y - x) != 0) {
            cout << -1 << "\n";
            return 0;
        }
        ll num = dif / (y - x);
        if (num > a[i]) {
            cout << -1 << "\n";
            return 0;
        }
        ans += a[i] - num;
    }
    cout << ans << "\n";
    return 0;
}
