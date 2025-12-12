#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];

  // 和をとる
  ll sum = 0;
  rep(i, N) sum += min(A[i], B[i]);
  while (Q--) {
    char c;
    int x, v;
    cin >> c >> x >> v;
    x--;

    vector<int> &target = (c == 'A' ? A : B);
    sum -= min(A[x], B[x]);
    target[x] = v;
    sum += min(A[x], B[x]);
    cout << sum << "\n";
  }
  return 0;
}
