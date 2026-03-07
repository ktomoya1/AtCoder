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

ll f(ll n) { return n * (n + 1) / 2; }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 解説AC
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = n;
    int pre = 0;
    // どこまで繰り返す？等差数列が終わるまで
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] - a[i - 1] != a[i + 1] - a[i]) {
            ans += f(i - pre);
            pre = i;
        }
    }
    ans += f(n - 1 - pre);
    cout << ans << "\n";
    return 0;
}
