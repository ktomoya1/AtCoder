#include <iostream>
using namespace std;

int main(void) {
	long long x, y, z;
	cin >> x >> y >> z;

	for (int i = 0; i <= 98; ++i) {
		int large = max(x, y);
		int small = min(x, y);

		if (large / small == z && large % small == 0) {
			cout << "Yes" << endl;
			return 0;
		}
		++x;
		++y;
	}
	cout << "No" << endl;
	return 0;
}