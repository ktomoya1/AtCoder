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

    // 間違えた原因：立式を間違えていた
    // A[i] - B[j] <= D-> x, |A[i] - B[j]| <= D -> o
    // |A[i] - B[j]| <= D -> B[j] - D <= A[i] << B[j] + D
    // この上限B[j] + DをAの中から探す
    int n, m; ll d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    // 二分探索の方法O(NlogN + MlogM)
    // sort(a.begin(), a.end());
    // ll ans = -1;
    // rep(i, m) {
    //     auto it = upper_bound(a.begin(), a.end(), b[i] + d);
    //     if (it == a.begin()) continue;
    //     --it;
    //     // 下限チェック
    //     if (*it >= b[i] - d) ans = max(ans, *it + b[i]);
    // }

    // 尺取り法O(N + M)
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = -1;
    int j = 0;
    rep(i, n) {
        // |A[i] - B[j]| <= D -> A[j] - D <= B[i] <= A[j] + D
        // b[j] + d >= a[i] X b[j] >= a[i] - dになるから下限を越えたら止まる
        while (j < m && b[j] <= a[i] + d) ++j;
        if (j > 0 && b[j - 1] >= a[i] - d) ans = max(ans, a[i] + b[j - 1]);
    }
    cout << ans << "\n";
    return 0;
}
