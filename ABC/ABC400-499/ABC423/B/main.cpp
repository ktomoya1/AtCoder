#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<int> L(N);
	for (int i = 0; i < N; ++i) cin >> L[i];
	
	int l = 0;
	int r = N - 1;
	while (l < r && L[l] != 1) ++l;
	while (r > l && L[r] != 1) --r;

	cout << r - l << endl;
	return 0;
}