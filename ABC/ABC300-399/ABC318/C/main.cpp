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

    ll N, D, P;
    cin >> N >> D >> P;
    vector<ll> F(N);
    rep(i, N) cin >> F[i];

    sort(F.rbegin(), F.rend());
    vector<ll> S(N + 1, 0);
    rep (i, N) S[i + 1] = F[i] + S[i];
    // 初期値：パスを１セットも買わない場合（通常料金の総和）
    ll ans = S[N];
    // セット数kを１セットから、全員分カバーするまで探索
    // kセットを買う = k * D 枚のパスがある

    for (ll k = 1; k <= (N + D - 1) / D; ++k) {
        ll cost = k * P; // パス代
        ll covered = min(N, k * D); // パスを使う日数（Nを超えないように）
        // パスを使わない残りの日の料金を加算
        //
        cost += (S[N] - S[covered]);
        ans = min(ans, cost);
    }
    cout << ans << "\n";
    return 0;
}
