#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	int Q;
	cin >> Q;

	// // stackを使ったやり方x
	// vector<string> s;
	// for (int i = 0; i < Q; ++i) {
	// 	int query_number;
	// 	cin >> query_number;
	// 	if (query_number == 1) {
	// 		string bracket;
	// 		cin >> bracket;
	// 		// 文字列は保存するようにし、括弧が閉じているか判断するのは後で行う
	// 		s.push_back(bracket);
	// 	} else {
	// 		if (!s.empty()) s.pop_back();
	// 	}
	// 	// スタックを使った判定
	// 	stack<string> stack;
	// 	for (string c : s) {
	// 		if (stack.empty()) stack.push(c);
	// 		else {
	// 			if (stack.top() == "(" && c == ")") stack.pop();
	// 			else stack.push(c);
	// 		}
	// 	}
	// 	if (stack.empty()) cout << "Yes" << endl;
	// 	else cout << "No" << endl; 
	// }

	// // 累積和を使ったやり方
	// vector<int> B;
	// for (int i = 0; i < Q; ++i) {
	// 	int query_num;
	// 	cin >> query_num;
	// 	if (query_num == 1) {
	// 		char c;
	// 		cin >> c;
	// 		if (B.empty()) {
	// 			if (c == '(') B.push_back(1);
	// 			else B.push_back(-1);
	// 		} else {
	// 			if (c == '(') B.push_back(B.back() + 1);
	// 			else B.push_back(B.back() - 1);
	// 		}
	// 	} else {
	// 		if (!B.empty()) B.pop_back();
	// 	}
	// 	// 途中に-1がないか確認する
	// 	auto min_it = min_element(B.begin(), B.end());
	// 	int min_value = *min_it;
	// 	if (min_value < 0) cout << "No" << endl;
	// 	else {
	// 		if (B.empty() || B.back() == 0) cout << "Yes" << endl;
	// 		else cout << "No" << endl;
	// 	}
	// }
	// 累積和+αを使ったやり方
	// vector<int> A; // Aiはiまでの和
	// vector<int> B; // Biはiまでのmin
	// A.push_back(0);
	// B.push_back(0);
	// for (int i = 0; i < Q; ++i) {
	// 	int cmd;
	// 	cin >> cmd;
	// 	if (cmd == 1) {
	// 		char c;
	// 		cin >> c;
	// 		if (c == '(') {
	// 			A.push_back(A.back() + 1);
	// 			B.push_back(min(B.back(), A.back())); // 更新前と更新後の値で比較
	// 		} else {
	// 			A.push_back(A.back() - 1);
	// 			B.push_back(min(B.back(), A.back()));
	// 		}
	// 	} else {
	// 		A.pop_back();
	// 		B.pop_back();
	// 	}
	// 	if (A.back() == 0 && B.back() == 0) cout << "Yes" << endl;
	// 	else cout << "No" << endl;
	// }

	// 値が負になった時点で負の要素を末尾に追加する方法
	vector<int> x = {0};
	const int INF = 1001001001;
	for (int i = 0; i < Q; ++i) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			char c;
			cin >> c;
			int nx = x.back() + (c == '(' ? 1 : -1);
			if (nx < 0) nx = -INF;
			x.push_back(nx);
		} else x.pop_back();
		if (x.back() == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}