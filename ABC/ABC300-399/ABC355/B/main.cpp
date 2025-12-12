#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	vector<int> A(N), B(M);
	// vector<pair<int, int>> C;
	vector<int> C;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		C.push_back(A[i]);
	}
	for (int j = 0; j < M; ++j) {
		cin >> B[j];
		C.push_back(B[j]);
	}
	sort(C.begin(), C.end());
	// // 愚直解
	// for (int i = 0; i < N - 1; ++i) {
	// 	for (int j = 0; j < N + M - 1; ++j) {
	// 		if (i + 1 < N && j + 1 < N + M) {
	// 			int minA = min(A[i], A[i + 1]), maxA = max(A[i], A[i + 1]);
	// 			if (minA == C[j] && maxA == C[j + 1]) {
	// 				cout << "Yes" << endl;
	// 				return 0;
	// 			}
	// 		}
	// 	}
	// }
	// // flagを使った解法
	// for (int i = 0; i < N + M - 1; ++i) {
	// 	if (C[i].second == 1 && C[i + 1].second == 1) {
	// 		cout << "Yes" << endl;
	// 		return 0;
	// 	}
	// }
	// setを使った解法
	set<int> st;
	for (int i = 0; i < N; ++i) st.insert(A[i]);
	for (int i = 0; i + 1 < N + M; ++i) {
		if (st.find(C[i]) != st.end() && st.find(C[i + 1]) != st.end()) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}