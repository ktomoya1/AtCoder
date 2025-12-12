#include <iostream>
using namespace std;

int main(void) {
	string X;
	cin >> X;

	sort(X.begin(), X.end());
	
	size_t non_zero_idx = 0;
	while (non_zero_idx < X.length()
				&& X[non_zero_idx] == '0') ++non_zero_idx;
	
	if (non_zero_idx < X.length()) swap(X[0], X[non_zero_idx]);

	cout << X << endl;
	return 0;
}