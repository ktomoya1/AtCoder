#include <iostream>
#include <vector>
using namespace std;

int sum_of_digits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(void) {
	int N;
	cin >> N;

	auto f = [](int n) -> int {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	};

	vector<int> A(N + 1);
	A[0] = 1;
	// 二重for文のやり方
	// iはAiのアクセス要素
	for (int i = 1; i <= N; ++i) {
		// jはf(Aj)のアクセス要素
		for (int j = 0; j <= i - 1; ++j) A[i] += f(A[j]);
	}
	// A[1] = 1;
	// for (int i = 2; i <= N; ++i) A[i] = A[i - 1] + f(A[i - 1]);
	cout << A[N] << endl;
	return 0;
}