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

    // 愚直解はO(N^2)でTLE
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    // 累積和を用意する
    vector<int> L(N, 0);
    vector<bool> seenL(N + 1, false);
    int countL = 0;
    rep(i, N) {
        if (!seenL[A[i]]) {
            countL++;
            seenL[A[i]] = true;
        }
        L[i] = countL;
    }
    vector<int> R(N, 0);
    vector<bool> seenR(N + 1, false);
    int countR = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (!seenR[A[i]]) {
            countR++;
            seenR[A[i]] = true;
        }
        R[i] = countR;
    }
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        // 左右の種類数を求める
        ans = max(ans, L[i] + R[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}
