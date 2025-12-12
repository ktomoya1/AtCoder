#include <iostream>
using namespace std;
using ll = long long;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N;
		ll H;
		cin >> N >> H;
		ll now = 0, low = H, high = H;
		bool possible = true;
		while (N--) {
			ll t, l, u;
			cin >> t >> l >> u;

			if (!possible) continue;
			// 目標時点の届く最低高度、最高高度を求める
			low = max(low - (t - now), l), high = min(high + (t - now), u);
			if (low > high) possible = false;
			now = t;
		}
		if (possible) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
	return 0;
}