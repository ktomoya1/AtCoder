#include <iostream>
using namespace std;

int H, B;

int main(void) {
	cin >> H >> B;
	if (H > B)
		cout << H - B << endl;
	else
		cout << 0 << endl;
	return 0;
}
