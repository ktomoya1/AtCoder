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

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

struct Problem {
    int N, M, X;
    vector<int> A, B;
};

// 尺取り法？違う、bit全探索？違う
// dp?
void solve (const Problem& p) {
    auto& [N, M, X, A, B] = p;

    // dp[i]: i段目に登ることができるならtrue, できないならfalse
    // DPの外側ループは段数：なぜなら、今回の状態は段数だから
    // vector<bool>でbit演算は使えない。なぜなら、各要素がビットで管理されているから
    vector<int> dp(X + 1), available(X + 1, 1);
    for (const auto b : B) available[b] = 0;
    dp[0] = 1;
    for (int i = 1; i <= X; ++i) {
        if (!available[i]) dp[i] = 0;
        else {
            for (const auto a : A) {
                if (i >= a)
                    dp[i] |= dp[i - a];
            }
        }
    }
    cout << (dp[X] ? "Yes" : "No") << "\n";
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    cin >> M;
    vector<int> B(M);
    rep(i, M) cin >> B[i];
    cin >> X;

    Problem prob = {N, M, X, A, B};
    solve(prob);
    return 0;
}
