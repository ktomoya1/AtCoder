#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, M, K;
	cin >> N >> M >> K;

	// 各参加者が問題を正解した問題数を格納するデータ型
	string answer = "";
	vector<int> counts(N + 1, 0);
	for (int i = 0; i < K; ++i) {
		int q_a, q_b;
		cin >> q_a >> q_b;
		++counts[q_a];
		if (counts[q_a] == M) {
			answer += to_string(q_a);
			answer += ' ';
		}
	}
	if (answer.empty()) return 0;
	cout << answer << endl;
	return 0;
}