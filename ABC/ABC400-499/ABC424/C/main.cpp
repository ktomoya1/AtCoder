#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> A(N, 0), B(N, 0);
  rep(i, N) cin >> A[i] >> B[i];

  queue<int> q;
  vector<bool> learned(N, false);
  // 最初に(0, 0)で習得済みのスキルを全てキューに入れる
  rep(i, N) {
    if (A[i] == 0 && B[i] == 0) {
      q.push(i);
      learned[i] = true;
    }
  }
  // 依存関係の逆引きリストを作成する
  vector<vector<int>> dep_list(N);
  rep(i, N) {
    if (A[i] != 0) dep_list[A[i] - 1].push_back(i); // スキルA[i]を前提とするスキルi
    if (B[i] != 0) dep_list[B[i] - 1].push_back(i);
  }
  


  // 習得済みスキルがなくなるまで続ける
  while (!q.empty()) {
    int current_skill = q.front();
    // スキルの依存元をなくす
    q.pop();

    for (int affected_skill : dep_list[current_skill]) {
      if ((learned[A[affected_skill] - 1] == true || learned[B[affected_skill] - 1] == true) && learned[affected_skill] == false) {
        learned[affected_skill] = true;
        q.push(affected_skill);
      }
    }
  }

  int ans = 0;
  rep(i, N) {
    if (learned[i] == true)
      ans++;
  }
  cout << ans << "\n";
	return 0;
}
