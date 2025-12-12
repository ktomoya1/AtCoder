#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
	string S;
	cin >> S;

	// // 辞書型で解く NlogN
	// map<char, int> map;
	// for (char c : S) ++map[c];
	// for (const auto& pair : map) {
	// 	if (pair.second == 1) cout << pair.first << endl;
	// }
	// // 大きさ順に並び替えて最初にあるか最後にあるか比較する
	// string T = S;
	// sort(T.begin(), T.end());
	// if (T[0] == T[1]) cout << T[T.size() - 1] << endl;
	// else cout << T[0] << endl;
	// unordered_mapで解く N
	unordered_map<char, int> counts;
	for (char c : S) ++counts[c];
	for (char c : S) {
		if (counts[c] == 1) {
			cout << c << endl;
			return 0;
		}
	}
	return 0;
}