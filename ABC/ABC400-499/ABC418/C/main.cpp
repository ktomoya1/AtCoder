#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  vector<ll> S(N + 1, 0);
  rep(i, N) S[i + 1] = S[i] + A[i];
  rep(i, N + 1) cout << S[i] << ' ';
  cout << endl;
  while (Q--) {
    int b;
    cin >> b;
    int ok = -1, ng = N;
    // 二分探索法
    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (A[mid] < b - 1) ok = mid;
      else ng = mid;
    }
    // SにAで探索してきたboundって適用できるの？
    // 予想：＋１する
    ll max_loss = S[ok + 1] + (ll)(N - (ok + 1)) * (b - 1);
    ll ans = max_loss + 1;

    if (ans > S[N]) cout << -1 << "\n";
    else cout << ans << "\n";
  }
  return 0;
}
