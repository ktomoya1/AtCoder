#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];

	vector<int> S(N);
	S[0] = A[0];
	for (int i = 1; i < N; ++i) S[i] = S[i - 1] + A[i];

	int ans = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i; j < N; ++j) {
			int sum;
			if (i == 0) sum = S[j];
			else sum = S[j] - S[i - 1];
			bool is_yakusu = false;
			for (int k = i; k <= j; ++k) {
				if (sum % A[k] == 0) {
					is_yakusu = true;
				}
			}
			if (is_yakusu == false)
				++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}