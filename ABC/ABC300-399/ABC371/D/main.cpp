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

    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i];

    // Pの累積和を作る
    vector<ll> S(N + 1, 0);
    rep (i, N) S[i + 1] = S[i] + P[i];

    int Q;
    cin >> Q;
    while (Q--) {
        ll l, r;
        cin >> l >> r;

        // ?何してるの？
        auto it_start = lower_bound(X.begin(), X.end(), l);
        auto it_end = upper_bound(X.begin(), X.end(), r);
        // ？イテレータには何がはいってるの？
        
        // ？なんでイテレータからXの最初の要素を引いたらインデックスが出てくる？
        int idx_start = it_start - X.begin();
        int idx_end = it_end - X.begin();

        ll ans = S[idx_end] - S[idx_start];
        cout << ans << "\n";
    }
    return 0;
}
