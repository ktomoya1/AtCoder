#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> pos_A;
  rep(i, 2 * N) {
    if (S[i] == 'A') pos_A.push_back(i);
  }

  ll ans1 = 0;
  ll ans2 = 0;
  int goal = 0;
  for (int i = 0; i < N; i++) {
    ans1 += abs(pos_A[i] - goal);
    goal++;
    ans2 += abs(pos_A[i] - goal);
    goal++;
  }
  cout << min(ans1, ans2) << "\n";
  return 0;
}
