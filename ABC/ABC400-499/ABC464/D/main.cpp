#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// WAの原因：前日からi日目に進む時に、i日目をどちらの天気で確定させるかを選ぶコストであり、
// i日目の中で晴れと雨を行き来するコストではないということに気づかなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // dp[2][n]: i日目が晴れ及び雨の時の嬉しさ
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> x(n), y(n - 1);
        rep(i, n) cin >> x[i];
        rep(i, n - 1) cin >> y[i];
        vector<vector<ll>> dp(2, vector<ll>(n));

        if (s[0] == 'S') dp[1][0] -= x[0];
        else dp[0][0] -= x[0];
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1] == 'S') {
                dp[0][i + 1] = max(dp[0][i], dp[1][i] + y[i]);
                dp[1][i + 1] = max(dp[0][i] - x[i + 1], dp[1][i] - x[i + 1]);
            } else {
                dp[0][i + 1] = max(dp[0][i] - x[i + 1], dp[1][i] - x[i + 1] + y[i]);
                dp[1][i + 1] = max(dp[0][i], dp[1][i]);
            }
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
    return 0;
}
