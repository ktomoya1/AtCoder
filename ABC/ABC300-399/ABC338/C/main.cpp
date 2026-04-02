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

    // ## 変数固定
    // - ２つの変数があって最適化したい時、片方を全探索で固定
    // 残りの変数の最大/最小を求める
    int n;
    cin >> n;
    vector<int> q(n), a(n), b(n);
    rep(i, n) cin >> q[i];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int min_d = 2e9;
    rep(i, n) {
        if (a[i])
            min_d = min(min_d, q[i] / a[i]);
    }
    int ans = -2e9;
    for (int x = 0; x <= min_d; x++) {
        int min_y = 2e9;
        for (int i = 0; i < n; i++) {
            if (b[i])
                min_y = min(min_y, (q[i] - a[i] * x) / b[i]);
        }
        ans = max(ans, x + min_y);
    }
    cout << ans << "\n";
    return 0;
}
