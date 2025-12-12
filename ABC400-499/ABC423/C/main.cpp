#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, R;
  cin >> N >> R;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L[i];

  int min_zero = -1, max_zero = -1;
  for (int i = 0; i < N; i++) {
    if (L[i] == 0) {
      if (min_zero == -1) min_zero = i;
      max_zero = i;
    }
  }
  if (min_zero == -1) {
    cout << '0' << "\n";
    return 0;
  }
  // 処理すべき範囲を決める
  int start = min(min_zero, R);
  int end = max(max_zero, R - 1);

  int sum_val = accumulate(L.begin() + start, L.begin() + end + 1, 0);
  int len = end - start + 1;

  cout << sum_val + len << "\n";
	return 0;
}
