#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int H, W;
	cin >> H >> W;

	
	// // 全探索の方法
	// // 黒マスの全てが、条件：上下左右で隣り合うマスのうち
	// // 黒く塗られているものが2つor４つである を満たすか確認する。
	// // 上マス(i - 1, j), 下マス(i + 1, j), 左マス(i, j - 1), 右マス(i, j + 1)
	// vector<string> S(H);
	// for (int i = 0; i < H; ++i) cin >> S[i];
	// for (int i = 0; i < H; ++i) {
	// 	for (int j = 0; j < W; ++j) {
	// 		while (S[i][j] == '.') ++j;
	// 		if (j == W) break;
	// 		int count = 0;
	// 		// Sが上辺(i == 0)の場合、(i - 1, j)はみない
	// 		if (i != 0 && S[i - 1][j] == '#') ++count;
	// 		// Sが下辺(i == H - 1)の場合、(i + 1, j)はみない
	// 		if (i != H - 1 && S[i + 1][j] == '#') ++count;
	// 		// Sが左辺(j == 0)の場合、(i, j - 1)はみない
	// 		if (j != 0 && S[i][j - 1] == '#') ++count;
	// 		// Sが右辺(j == W - 1)の場合、(i, j + 1)はみない
	// 		if (j != W - 1 && S[i][j + 1] == '#') ++count;
	// 		if (count != 2 && count != 4) {
	// 			cout << "No" << endl;
	// 			return 0;
	// 		}
	// 	}
	// }

	// 上下左右に.を追加する方法
	// この方法なら、上下左右の辺にあるか確認する条件分岐を減らせる
	vector field(H + 2, string(W + 2, '.'));

	for (int i = 1; i < H + 1; ++i) {
		string S;
		cin >> S;
		field[i] = '.' + S + '.';
	}

	for (int i = 1; i < H + 1; ++i) {
		for (int j = 1; j < W + 1; ++j) {
			while (j < W + 1 && field[i][j] == '.') ++j;
			if (j == W + 1) break;
			int black_count = 0;
			if (field[i - 1][j] == '#') ++black_count;
			if (field[i + 1][j] == '#') ++black_count;
			if (field[i][j - 1] == '#') ++black_count;
			if (field[i][j + 1] == '#') ++black_count;
			if (black_count != 2 && black_count != 4) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}