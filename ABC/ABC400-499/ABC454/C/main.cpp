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

// DFS
// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     // ## 有向グラフ, DFS, BFS
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> g(n);
//     rep(i, m) {
//         int a, b;
//         cin >> a >> b;
//         a--; b--;
//         g[a].push_back(b);
//     }
//
//     // vector<bool>は自動でfalseに初期化する
//     vector<bool> seen(n);
//     auto dfs = [&](auto self, int v) -> void {
//         seen[v] = true;
//         for (auto next : g[v]) {
//             if (seen[next]) continue;
//             self(self, next);
//         }
//     };
//
//     dfs(dfs, 0);
//     int ans = 0;
//     rep(i, n) {
//         if (seen[i]) ans++;
//     }
//     cout << ans << "\n";
//     return 0;
// }

// BFS
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    // 注意！ seen=trueにするタイミングをミスるとTLE
    // 見たとマークをつけるタイミングがキューにプッシュしてからだと、
    // 他のノードが対象ノードを見る際に見てないと判断し、
    // 同じノードをプッシュして無駄な処理が発生→TLE
    queue<int> q;
    vector<bool> seen(n);
    seen[0] = true;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next : g[cur]) {
            if (seen[next]) continue;
            seen[next] = true;
            q.push(next);
        }
    }
    int ans = 0;
    rep(i, n) {
        if (seen[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
