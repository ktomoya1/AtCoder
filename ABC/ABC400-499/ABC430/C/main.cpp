#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, A, B;
	cin >> N >> A >> B;
	string S;
	cin >> S;

	long long ans = 0;
	// // 愚直解
	// for (int start = 0; start <= N - A; ++start) {
	// 	int a_cnt = 0, b_cnt = 0;
	// 	for (int end = start; end < N; ++end) {
	// 		if (S[end] == 'a') ++a_cnt;
	// 		else ++b_cnt;
	// 		if (b_cnt == B) break;
	// 		else if (a_cnt >= A && b_cnt < B) ++ans;
	// 	}
	// }
	// 累積和＋尺取り法
	vector<int> sa(N + 1), sb(N + 1);
	for (int i = 1; i <= N; ++i) {
		sa[i] = S[i - 1] == 'a';
		sb[i] = S[i - 1] == 'b';
		sa[i] += sa[i - 1];
		sb[i] += sb[i - 1];
	}
	int p = 0, q = 0;
	for (int i = 1; i <= N; ++i) {
		while (p < i && sa[i] - sa[p] >= A)
			++p;
		while (q < i && sb[i] - sb[q] >= B)
			++q;
		ans += max(0, p - q);
	}
	cout << ans << endl;
	return 0;
}