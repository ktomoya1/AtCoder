#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int N, M;
// vector<pair<int, int>> edges;
// vector<int> color;
// int ans = 1000000;

// // (v: 今から色を決める頂点の番号)
// void dfs(int v) {
// 	// 全部の色を決め終わった時
// 	if (v == N + 1) {
// 		int delete_count = 0; // 今回のパターンでの削除本数

// 		for (auto edge : edges) {
// 			int u = edge.first;
// 			int v = edge.second;

// 			// 同じ色なら、二部グラフのルール違反なので削除対象
// 			if (color[u] == color[v])
// 				delete_count++;
// 		}
// 		// 今回の削除数が、今までの最小記録より小さければ更新
// 		ans = min(ans, delete_count);

// 		return;
// 	}

// 	// まだ決めてない頂点がある時

// 	// パターンA： 頂点vを白にして、次(v+1)へ
// 	color[v] = 0;
// 	dfs(v + 1);
// 	// パターンB： 頂点vを黒にして、次(v+1)へ
// 	color[v] = 1;
// 	dfs(v + 1);
// }

int main(void) {
	// cin >> N >> M;
	// for (int i = 0; i < M; ++i) {
	// 	int u, v;
	// 	cin >> u >> v;
	// 	edges.push_back({u, v});
	// }
	// // 配列のサイズ確保(１番〜N番を使うのでN+1)
	// color.resize(N + 1);

	// // 全探索スタート
	// dfs(1);

	// bit全探索
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> edges;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		edges.push_back({u, v});
	}

	int ans = 1000000;

	// bitを0から(2^N - 1)まで回す
	// これで全員白から全員黒まで全パターン作れる
	for (int bit = 0; bit < (1 << N); ++bit) {
		vector<int> color(N);
		for (int i = 0; i < N; ++i) {
			if (bit & (1 << i)) color[i] = 1;
			else color[i] = 0;
		}
		
		int delete_count = 0;
		for (auto edge : edges) {
			int u = edge.first;
			int v = edge.second;
			if (color[u] == color[v]) ++delete_count;
		}

		ans = min(ans, delete_count);
	}

	cout << ans << endl;
	return 0;
}