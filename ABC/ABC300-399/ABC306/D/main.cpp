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

    // ## 二次元DP
    // DPだと気づけなかった理由：全探索で2^N通りあり、制約通りに行くとvectorのサイズに収まらないと思ったから
    // しかし、サイズが2^Nになるのは、選んだ結果全てを保持しなければいけないとき
    // 今回は、最終的に「健康」と「不調」の状態の美味しさの最大値、つまり２つだけ持ってれば良いため、
    // サイズはN*2ですむ
    int n;
    cin >> n;
    vector<int> x(n);
    vector<ll> y(n);
    rep(i, n) cin >> x[i] >> y[i];

    const ll NEG_INF = -4e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, NEG_INF));
    dp[0][0] = 0;
    rep(i, n) {
        // 遷移状態
        // 共通項：料理を下げるとき
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
        if (!x[i]) { // 解毒料理のとき、1->0へ
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + y[i]);
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + y[i]);
        } else { // 毒入り料理のとき,0->1へ
            // 下げた場合の最大値と食べた場合の最大値と比べて、大きい方を残す
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + y[i]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
    return 0;
}
