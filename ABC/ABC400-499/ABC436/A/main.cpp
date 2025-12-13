#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  string S;
  cin >> N >> S;
  string T(N - S.size(), 'o');
  cout << T << S << "\n";
}
