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

    int l, r, d, u;
    cin >> l >> r >> d >> u;

    int m = max({abs(l), abs(r), abs(d), abs(u)});
    vector<ll> s(m + 1);
    ll ans = 0;
    rep(k, m + 1) {
        ll w = max(0, min(r, k) - max(l, -k) + 1);
        ll h = max(0, min(u, k) - max(d, -k) + 1);
        s[k] = w * h;
        if (k == 0) {
            ans += s[k];
        }
        else if (k && k % 2 == 0)
            ans += s[k] - s[k - 1];
    }
    cout << ans << "\n";
    return 0;
}
