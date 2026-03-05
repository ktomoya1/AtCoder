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

    int n;
    cin >> n;
    vector<int> k(n);
    ll total_sum = 0;
    rep(i, n) {
        cin >> k[i];
        total_sum += k[i];
    }

    ll max_sum = -2e9;
    ll ans = 2e9;
    for (int bit = 0; bit < (1 << n); ++bit) {
        ll sum_a = 0;
        for (int digit = 0; digit < n; ++digit) {
            if (bit & (1 << digit)) sum_a += k[digit];
        }
        ll sum_b = total_sum - sum_a;
        max_sum = max(sum_a, sum_b);
        ans = min(ans, max_sum);
    }
    cout << ans << "\n";
    return 0;
}
