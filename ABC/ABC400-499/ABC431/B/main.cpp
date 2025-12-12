#include <iostream>
using namespace std;

int X, N;
int W[109];
int Q;
int P[109];
bool flag[109] = {false};
int answer;

int main(void) {
	cin >> X >> N;
	for (int i = 1; i <= N; ++i) cin >> W[i];
	cin >> Q;
	for (int i = 1; i <= Q; ++i) cin >> P[i];
	answer = X;
	for (int i = 1; i <= Q; ++i) {
		if (flag[P[i]] == false) {
			answer += W[P[i]];
			flag[P[i]] = true;
		} else {
			answer -= W[P[i]];
			flag[P[i]] = false;
		}
		cout << answer << endl;
	}
	return 0;
}