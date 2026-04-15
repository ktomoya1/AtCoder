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

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     // ## 二分探索, 尺取り法
//     // lower_bound: value以上の出現位置
//     // upper_bound: valueより大きい出現位置
//     // ai + mの境界を知りたい->ai + m以上を探す
//     int n; ll m;
//     cin >> n >> m;
//     vector<ll> a(n);
//     rep(i, n) cin >> a[i];
//     sort(a.begin(), a.end());
//     int ans = 0;
//     rep(i, n) {
//         int rid = lower_bound(a.begin(), a.end(), a[i] + m) - a.begin();
//         ans = max(ans, rid - i);
//     }
//     cout << ans << "\n";
//     return 0;
// }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 尺取り法
    int n; ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    // lを固定する
    int r = 0;
    int ans = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && a[r] < a[l] + m) r++;
        ans = max(ans, r - l);
    }
    cout << ans << "\n";
    return 0;
}
