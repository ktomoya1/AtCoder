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

    int N, L;
    cin >> N >> L;

    if (L % 3 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> d(N - 1);
    rep(i, N - 1) cin >> d[i];

    int x = 0;
    vector<int> cnt(L, 0);

    rep(i, N) {
        if (i != 0) {
            x += d[i - 1];
        }
        x %= L;
        cnt[x]++;
    }

    ll ans = 0;
    rep(i, L / 3) {
        ans += (ll)cnt[i] * cnt[i + L / 3] * cnt[i + 2 * L / 3];
    }
    cout << ans << "\n";
    return 0;
}
