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

#define rep(i, l, r) for (int i = (l); i < (r); i++)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;
    vector<ll> a(2 * n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i] %= k;
        a[n + i] = a[i] + k;
    }
    sort(a.begin(), a.end());
    ll ans = 2e9;
    rep(i, 0, n) {
        ans = min(ans, a[n + i - 1] - a[i]);
    }
    cout << ans << "\n";
    return 0;
}
