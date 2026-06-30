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

// WAの原因：modで余りを取りわすれ
// このdpは加算ステップごとに最大２倍ずつ値が増える、n-1回の遷移で最大2^(n-1)倍
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // FGの操作を繰り返した後に最終的に残るKの値(0-9)の頻度分布を求める
    // bit全探索は2^10000より無理っぽい
    // dpっぽい？
    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(10));
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    const int m = 998244353;

    dp[0][a[0]] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 10; j++) {
            if (dp[i][j] > 0) {
                dp[i + 1][(j + a[i + 1]) % 10] += dp[i][j] % m;
                dp[i + 1][(j * a[i + 1]) % 10] += dp[i][j] % m;
                dp[i + 1][(j + a[i + 1]) % 10] %= m;
                dp[i + 1][(j * a[i + 1]) % 10] %= m;
            }
        }
    }
    rep(i, 10) cout << dp[n - 1][i] << "\n";
    return 0;
}
