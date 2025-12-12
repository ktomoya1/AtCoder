#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, Q;
	cin >> N >> Q;

	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) A.push_back(A[i]);
	vector<long long> S(N * 2 + 1, 0);
	for (int i = 0; i < 2 * N; ++i) S[i + 1] = S[i] + A[i % N];

	int offset = 0;
	for (int q = 0; q < Q; ++q) {
		int command;
		cin >> command;
		if (command == 1) {
			int c;
			cin >> c;
			offset += c;
			offset %= N;
		} else {
			int l, r;
			cin >> l >> r;
			cout << S[offset + r] - S[offset + l - 1] << "\n";
		}
	}
	return 0;
}