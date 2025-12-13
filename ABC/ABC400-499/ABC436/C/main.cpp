#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  set<pair<int, int>> set;
  int ans = 0;
  while (M--) {
    int r, c;
    cin >> r >> c;
    if (set.count({r, c}) == 0 && set.count({r + 1, c}) == 0 && set.count({r, c + 1}) == 0 && set.count({r + 1, c + 1}) == 0) {
      set.insert({r, c});
      set.insert({r + 1, c});
      set.insert({r, c + 1});
      set.insert({r + 1, c + 1});
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
