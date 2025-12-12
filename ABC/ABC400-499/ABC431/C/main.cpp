#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main(void) {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> H(N), B(M);
	for (int i = 0; i < N; ++i) cin >> H[i];
	for (int i = 0; i < M; ++i) cin >> B[i];

	sort(H.begin(), H.end());
	sort(B.begin(), B.end());
	int count = 0;
	int j = 0;
	for (int i = 0; i < N; ++i) {
		while (j < M && H[i] > B[j]) ++j;
		if (j < M) {
			++count;
			++j;
		}
		if (count == K) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}