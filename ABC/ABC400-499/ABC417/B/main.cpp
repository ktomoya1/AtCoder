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

    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(j, M) cin >> B[j];
    sort(B.begin(), B.end());
    vector<bool> is_used(N, false);
    int j = 0;
    rep(i, N) {
        while (j < M && B[j] < A[i])
            j++;
        if (A[i] == B[j]) {
            is_used[i] = true;
            j++;
        }
    }
    rep(i, N) {
        if (is_used[i])
            continue;
        cout << A[i] << (i == N - 1 ? '\n' : ' ');
    }
    return 0;
}
