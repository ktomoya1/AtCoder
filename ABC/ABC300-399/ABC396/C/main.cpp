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

    // 愚直解はO(NM) (TLE)
    // 貪欲法っぽい
    int N, M;
    cin >> N >> M;
    vector<int> B(N), W(M);
    rep(i, N) cin >> B[i];
    rep(j, M) cin >> W[j];
    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend());
    // 黒色のボールの個数が白色のボールの個数以上になるようにボールを選ぶのが辛い
    // 累積和も使った方が良さそう
    vector<ll> S_B(N + 1, 0), S_W(M + 1, 0);
    rep(i, N) S_B[i + 1] = S_B[i] + B[i];
    rep(j, M) S_W[j + 1] = S_W[j] + W[j];
    ll ans = 0;
    ll max_white_val = 0;
    for (int i = 1; i <= N; i++) {
        max_white_val = max(max_white_val, S_W[min(i, M)]);
        ans = max(ans, S_B[i] + max_white_val);
    }
    cout << ans << "\n";
    return 0;
}
