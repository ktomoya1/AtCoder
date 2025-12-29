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

    // 1 <= i < j <= Nを満たす全てのi, jの組についての|Ai - Aj|の和を求めよ。
    // 愚直解
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        int plus_count = i;
        int minus_count = N - 1 - i;

        sum += A[i] * plus_count;
        sum -= A[i] * minus_count;
    }
    cout << sum << "\n";
    return 0;
}
