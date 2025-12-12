#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) cin >> A[i];

	if (A[1] == 1) {
		cout << "1" << endl;
		return 0;
	}
	int ans = 0;
	int count = 1;
	for (int i = 1; i <= N; ++i) {
		while (count > 0 && i <= N) {
			count = max(count, A[i]);
			// cout << "i: " << i << ", " << "count: " << count << endl;
			++i;
			count--;
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}