#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<string> S(N);
	for (int i = 0; i < N; ++i) cin >> S[i];

	// M行M列のstringを重複なしで格納するデータ型：set型
	set<vector<string>> Answer;
	// M行M列を切り取ってset型に格納する
	// 行を動かす
	for (int i = 0; i < N - M + 1; ++i) {
		for (int j = 0; j < N - M + 1; ++j) {
			// M行M列を１行ずつ作っていく
			vector<string> grid;
			for (int ii = i; ii < i + M; ++ii) grid.push_back(S[ii].substr(j, M));
			Answer.insert(grid);
		}
	}
	cout << Answer.size() << endl;
	return 0;
}