#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	vector<int> A(3);
	cin >> A[0] >> A[1] >> A[2];

	sort(A.begin(), A.end(), greater<int>());
	cout << A[0] * 100 + A[1] * 10 + A[2] << endl;
	return 0;
}