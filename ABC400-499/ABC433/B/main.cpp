#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	
	vector<int> m(N);
	m[0] = A[0];
	for (int i = 1; i < N; ++i) m[i] = max(m[i - 1], A[i]);

	for (int i = 0; i < N; ++i) {
		if (A[i] == m[i]) cout << "-1" << endl;
		else {
			for (int j = i; j >= 0; --j) {
				if (A[j] > A[i]) {
					cout << j + 1 << endl;
					break;
				}
			}
		}
	}
	return 0;
}