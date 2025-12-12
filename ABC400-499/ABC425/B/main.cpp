#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];

	// Noになる条件を見つける
	// 同じ数値が使われたかどうか判定する
	vector<bool> used(N + 1, false);
	for (int i = 0; i <= N; ++i) {
		if (A[i] == -1)
			continue;
		if (used[A[i]] == true) {
			cout << "No" << endl;
			return 0;
		}
		used[A[i]] = true;
	}
	cout << "Yes" << endl;
	// 順列Pの構築
	int j = 1;
	for (int i = 0; i < N; ++i) {
		if (A[i] != -1) continue;
		while (j <= N && used[j] == true)
			++j;
		A[i] = j;
		++j;
	}
	for (int i = 0; i < N; ++i) cout << A[i] << ' ';
	cout << endl;
	return 0;
}