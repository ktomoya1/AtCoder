#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  ll na, nb, nc;
  cin >> na >> nb >> nc;

  auto check = [&](ll x) -> bool {
    return x <= na && x <= nc && 3 * x <= (na + nb + nc);
  };

  ll ok = 0;
  ll ng = 2e9;

  while (abs(ng - ok) > 1) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";

}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
	return 0;
}
