#include <iostream>
#include <vector>
using namespace std;

int calc_distance(int a, int b, int c, int x) {
	int distance = 0;
	// // 愚直解
	// for (int t = 0; t < x; ++t) {
	// 	if (t % (a + c) < a) distance += b;
	// }
	// 計算式の方法 O(1)
	int set = x / (a + c);
	int r = x % (a + c);

	distance += b * (set * a);
	distance += b * min(r, a);

	return distance;
}

int main(void) {
	int a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;

	int takahashi = calc_distance(a, b, c, x);
	int aoki = calc_distance(d, e, f, x);

	if (takahashi > aoki) cout << "Takahashi" << endl;
	else if (takahashi < aoki) cout << "Aoki" << endl;
	else cout << "Draw" << endl;

	return 0;
}