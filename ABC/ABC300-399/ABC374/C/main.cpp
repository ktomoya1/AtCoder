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
#include <functional>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> k(n);
    ll total_sum = 0;
    rep(i, n) {
        cin >> k[i];
        total_sum += k[i];
    }
    ll ans = 1e18;
    function<void(ll, int)> dfs = [&](ll sum_a, int i) {
        if (i == n) {
            ll sum_b = total_sum - sum_a;
            ans = min(ans, max(sum_a, sum_b));
            return;
        }
        dfs(sum_a + k[i], i + 1);
        dfs(sum_a, i + 1);
    };
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}
