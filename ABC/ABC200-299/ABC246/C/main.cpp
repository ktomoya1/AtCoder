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

// 28分AC、だけどWA2回
// 原因：countをa[i] / xのみにすると、a[i] / xよりkが小さかった時にa[i]を余分に減算してしまう。
// kは必ず0にしなければならない
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 最初からソートしなくていい
    // 一度A1~AnからKの数だけXを引いていく
    // 残った数字を降順にソート、Kがなくなるまで0にしていく、無くなった先から足す
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    for (int i = 0; i < n && k; i++) {
        if (a[i] >= x) {
            ll count = min(a[i] / x, k);
            a[i] -= x * count;
            k -= count;
        }
    }
    ll ans = 0;
    if (!k) {
        rep(i, n) ans += a[i];
        cout << ans << "\n";
        return 0;
    }

    sort(a.rbegin(), a.rend());
    rep(i, n) {
        if (k) {
            k--;
        } else {
            ans += a[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
