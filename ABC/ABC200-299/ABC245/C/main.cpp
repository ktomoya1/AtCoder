#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<bool> dp_A(N, false), dp_B(N, false);

    dp_A[0] = true; dp_B[0] = true;
    for (int i = 1; i < N; i++) {
        if (dp_A[i - 1] == true) {
            if (abs(A[i] - A[i - 1]) <= K) dp_A[i] = true;
            if (abs(B[i] - A[i - 1]) <= K) dp_B[i] = true;
        }
        if (dp_B[i - 1] == true) {
            if (abs(A[i] - B[i - 1]) <= K) dp_A[i] = true;
            if (abs(B[i] - B[i - 1]) <= K) dp_B[i] = true;
        }
    }
    for (int i = 1; i < N; i++) {
        if (dp_A[i] == false && dp_B[i] == false) {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}
