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

// dpの思いつきかた:
// 1. 全探索できるか？->桁数N = 10^6, 各桁9^(10^6)で無理
// 2. 左から順に決めていけるか？->1桁目, 2桁目, ...と順に決められる
// 3. i桁目を決めるのに必要な情報は何か？->直前の桁の値だけ。それより前は不要
// 4. 同じ状態が何度も出てくるか？->i桁目がdという状態は複数経路で存在する。毎回数え直すのは無駄
// 全問題に共通して言えること：今の選択に必要な情報が、過去の全履歴ではなく一部の状態だけで表せること
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(10));

    for (int d = 1; d <= 9; d++) dp[1][d] = 1;
    for (int i = 1; i < n; i++) {
        for (int d = 1; d <= 9; d++) {
            for (int nd = max(1, d - 1); nd <= min(9, d + 1); nd++) {
                dp[i + 1][nd] = (dp[i + 1][nd] + dp[i][d]) % 998244353;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[n][i];
        ans %= 998244353;
    }
    cout << ans << "\n";
    return 0;
}
