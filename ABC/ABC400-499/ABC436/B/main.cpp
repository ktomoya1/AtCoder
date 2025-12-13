#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<vector<int>> A(N, vector(N, 0));

  int r = 0, c = (N - 1) / 2;
  int k = 1;
  A[r][c] = k;
  rep(i, N * N - 1) {
    k++;
    int nr = (r - 1 + N) % N, nc = (c + 1) % N;
    if (A[nr][nc] == 0) {
      r = nr;
      c = nc;
    } else {
      r = (r + 1) % N;
    }
    A[r][c] = k;
  }
  rep(i, N) {
    rep(j, N) {
      cout << A[i][j] << (j == N - 1 ? "\n" : " ");
    }
  }
  return 0;
}
