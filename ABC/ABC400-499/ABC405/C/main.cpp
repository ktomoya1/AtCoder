#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<long long> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];

	long long ans = 0;
	// // ナイーブ解　TLE
	// for (int i = 0; i < N; ++i) {
	// 	for (int j = i + 1; j < N; ++j) ans += A[i] * A[j];
	// }
	// // 和の二乗の公式を利用した方法
	// // (A1 + A2 + ... + AN)^2 = sigma(i=1)N Ai^2 + 2sigma(1<=i<j<=N)AiAj
	// // sigma(1<=i<j<=N)AiAj = ((A1 + A2 + ... + AN)^2 - sigma(i=1)N Ai^2) / 2
	// long long sigma1 = 0, sigma2 = 0;
	// for (int i = 0; i < N; ++i) {
	// 	sigma1 += A[i];
	// 	sigma2 += A[i] * A[i];
	// }
	// ans = (sigma1 * sigma1 - sigma2) / 2;
	// 累積和を利用した方法
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		ans += A[i] * sum;
		sum += A[i];
	}
	cout << ans << endl;
	return 0;
}