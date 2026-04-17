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

    // # DFS, 重みつき無向グラフの最長経路
    // 間違えた原因：n個全部訪問したときにansを更新していた。
    // 本当は途中で行き止まりになったパスも記録して良かった。
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a][b] = c;
        g[b][a] = c;
    }

    vector<bool> seen(n, false);
    int ans = 0;
    auto dfs = [&](auto self, int v, int sum) -> void {
        seen[v] = true;
        for (int i = 0; i < n; i++) {
            if (!g[v][i] || seen[i]) continue;
            self(self, i, sum + g[v][i]);
        }
        seen[v] = false;
        // これ以上進めなくなった街の最長距離を測る
        ans = max(ans, sum);
    };
    rep(i, n) {
        dfs(dfs, i, 0);
    }
    cout << ans << "\n";
    return 0;
}
