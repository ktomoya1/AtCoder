#include <iostream>
#include <vector>
using namespace std;

long long c2(long long n) {
	return n * (n - 1) / 2;
}

int main(void) {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];

	// // 愚直解 O(N^3)
	// int ans = 0;
	// for (int i = 0; i < N; ++i) {
	// 	for (int j = i + 1; j < N; ++j) {
	// 		for (int k = j + 1; k < N; ++k) {
	// 			cout << "i: " << i << "j: " << j << "k: " << k << endl;
	// 			if ((A[i] != A[j] && A[j] == A[k])
	// 			|| (A[j] != A[k] && A[i] == A[k])
	// 			|| (A[k] != A[i] && A[i] == A[j])) {
	// 				++ans;
	// 			}
	// 		}
	// 	}
	// }

	// A[i], A[j], A[k]の順番は関係ない
	// 頻度分布を作る
	vector<int> cnt(N);
	for (int i = 0; i < N; ++i) ++cnt[A[i] - 1];

	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += c2(cnt[i]) * (N - cnt[i]);
	}
	cout << ans << endl;
	return 0;
}