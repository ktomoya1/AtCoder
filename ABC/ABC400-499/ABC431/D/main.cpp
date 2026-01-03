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

    // 求めるのは嬉しさの最大合計
    // 頭の重さ < 体の重さでなければならない
    // W_head: 頭の重さの合計、W_body: 体の重さの合計とする
    // W_head < W_body -> W_head < S - W_head → W_head < S / 2
    // 全探索ではO(N^2)→DP！
    int N;
    cin >> N;
    vector<ll> W(N), H(N), B(N);

    ll total_weight = 0;
    ll base_happiness = 0; // 全員「体」にしたときの価値
    rep(i, N) {
        cin >> W[i] >> H[i] >> B[i];
        // 全体の重さをとる
        total_weight += W[i];
        base_happiness += B[i];
    }

    ll capacity = total_weight / 2;
    // dp[w] = 頭の重さがwの時の、「嬉しさの最大増分
    vector<ll> dp(capacity + 1, -1);
    dp[0] = 0;

    rep(i, N) {
        // もし「頭にした方が損する（H < B）なら、絶対に「体」のままでいい
        // 逆にH > Bなら、コストW[i]を払って価値（H - B）を得るか考える
        ll gain = H[i] - B[i];
        if (gain <= 0) continue;

        ll weight = W[i];
        // 重い方から回す（１次元配列でナップサックをするときの定石
        // なんでw = capacityから始めるの？→ weightより下の重さのアイテムはすでに使っているため
        for (int w = capacity; w >= weight; --w) {
            if (dp[w - weight] != -1)
                dp[w] = max(dp[w], dp[w - weight] + gain);
        }
    }
    ll max_gain = 0;
    for (int w = 0; w <= capacity; ++w) max_gain = max(max_gain, dp[w]);
    // なんでbase_happinessと足すの？→元々体の差分を求める話だったから
    cout << base_happiness + max_gain << "\n";
    return 0;
}
