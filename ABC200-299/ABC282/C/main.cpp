#include <iostream>
using namespace std;

int main(void) {
	int N;
	string S;
	cin >> N >> S;

	// // 変数展開のやり方 5ms
	// bool is_quoted = false;
	// for (int i = 0; i < N; ++i) {
	// 	if (S[i] == '"' && is_quoted == false) is_quoted = true;
	// 	else if (S[i] == '"') is_quoted = false;
	// 	else {
	// 		if (S[i] == ',' && is_quoted == false) S[i] = '.';
	// 	}
	// }
	// 改良版 4ms
	for (int i = 0; i < N; ++i) {
		if (S[i] == '"') {
			++i;
			while (i < N && S[i] != '"') ++i;
			if (i == N) break;
		} else if (S[i] == ',') S[i] = '.';
	}
	cout << S << endl;
	return 0;
}