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

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

void solve2(ll N, ll K, const vector<vector<ll>>& A, const vector<ll>& C, const vector<ll>& L) {
    --K;
    rep(i, N) {
        if (K < C[i] * L[i]) {
            cout << A[i][K % L[i]] << "\n";
            return;
        }
        K -= C[i] * L[i];
    }
}

void solve(ll N, ll K, const vector<vector<ll>>& A, const vector<ll>& C, const vector<ll>& L) {
    vector<ll> CL(N + 1);
    rep(i, N) CL[i + 1] = C[i] * L[i];
    rep(i, N) CL[i + 1] += CL[i];

    // Kがちょうど境界に一致するとき、upper_boundはその先を指定しまう。
    // -1してるのは、CLの累積和によるインデックスのずれをAに合わせるため。
    int id = lower_bound(CL.begin(), CL.end(), K) - CL.begin() - 1;
    // A[id]を求める
    int offset = (K - CL[id] - 1) % L[id];
    cout << A[id][offset] << "\n";
}

// 時間がかかった原因：入力する値を間違えた。lower_boundとupper_boundの違い
// 入力する値を間違えたのは疲れ
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1≤K≤∑^N_(i=1)C_i*L_iの理由: Nがいくら大きくても、ループの総回数はΣLiに縛られる
    // 具体例：N=10^5の時、L=[1, 1, ..., 1]->∑^N_(i=1)Li = 1 * 10^5 <= 2 * 10^5
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> A(N);
    vector<ll> L(N);
    rep(i, N) {
        cin >> L[i];
        rep(j, L[i]) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    vector<ll> C(N);
    rep(i, N) cin >> C[i];

    solve2(N, K, A, C, L);
 //   solve(N, K, A, C, L);

    return 0;
}
