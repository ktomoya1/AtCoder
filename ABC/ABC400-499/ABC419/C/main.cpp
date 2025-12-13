#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int min_y = 2e9, max_y = -2e9, min_x = 2e9, max_x = -2e9;
  rep(i, N) {
    int r, c;
    cin >> r >> c;
    min_y = min(min_y, r);
    max_y = max(max_y, r);
    min_x = min(min_x, c);
    max_x = max(max_x, c);
  }
  
  int dist_y = max_y - min_y;
  int dist_x = max_x - min_x;
  dist_y = (dist_y + 1) / 2;
  dist_x = (dist_x + 1) / 2;
  cout << max(dist_y, dist_x) << "\n";
  return 0;
}
