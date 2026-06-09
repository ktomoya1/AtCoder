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
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// WAの原因:部分列だしdpっぽい？->座標の制約が1<=Ai<10^9で厳しそう...
// ->本当はmapで管理すればよかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // unordered_mapはdp[key]アクセス時に0になるため、
    // 以前の状態を知るのに余計な初期化処理を挟まずに済む
    unordered_map<int, int> dp; // dp[v] = vで終わる部分列の総数
    int ans = 0;
    // O(N)
    rep(i, n) {
        int a;
        cin >> a;
        // unordered_mapのアクセス計算量はO(1)
        dp[a] = dp[a - 1] + 1;
        ans = max(ans, dp[a]);
    }
    cout << ans << "\n";
    return 0;
}
