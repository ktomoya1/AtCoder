#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(void) {
	// 種類のカウントを作る
	int N, M;
	cin >> N >> M;

	vector<double> weight(M + 1, 0);
	vector<int> count(M + 1, 0);
	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;
		weight[a] += b;
		++count[a];
	}
	for (int i = 1; i <= M; ++i) {
		cout << weight[i] / count[i] << "\n";
	}
	return 0;
}