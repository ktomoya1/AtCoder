#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, Q;
	cin >> N >> Q;

	// // 愚直解 TLE
	// vector<int> pc(N + 1);
	// for (int i = 1; i <= N; ++i) pc[i] = i;
	// for (int i = 0; i < Q; ++i) {
	// 	int x, y;
	// 	cin >> x >> y;
	// 	int count = 0;
	// 	for (int j = 1; j <= N; ++j) {
	// 		if (pc[j] <= x) {
	// 			pc[j] = y;
	// 			++count;
	// 		}
	// 	}
	// 	cout << count << endl;
	// }
	
	// 解説の解
	vector<int> vers(N + 1, 1);
	vers[0] = 0;
	int o = 1;
	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y;
		int count = 0;
		for (int j = o; j <= x; ++j) {
			count += vers[j];
			vers[j] = 0;
		}
		vers[y] += count;
		if (o <= x)
			o = x + 1;
		cout << count << endl;
	}
	return 0;
}