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

    // imos+二分探索？
    int N, M;
    cin >> N >> M;
    vector<int> L(M), R(M);
    rep(i, M) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        L[i] = l;
        R[i] = r;
    }

    vector<int> imos(N + 1, 0);
    rep(i, M) {
        imos[L[i]] += 1;
        imos[R[i] + 1] -= 1;
    }
    rep(i, N) imos[i + 1] += imos[i];
    int ans = 1e9;
    rep(i, N) {
        ans = min(ans, imos[i]);
    }
    cout << ans << "\n";
    return 0;
}
