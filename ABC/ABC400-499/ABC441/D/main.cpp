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

// AC：時間がかかった理由：データ型の選定に時間がかかった+出力がi+1ではなくans[i] + 1にしてしまったこと
// 計算量：出次数が最大４、L<=10より、O(4^10)=約100万->10^6
// 深さ0: 1ノード（頂点１）
// 深さ1: 最大4ノード
// 深さ2: 最大4^2ノード
// ...
// 深さL: 最大4^Lノード
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, l;
    ll s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<pair<int, ll>>> g(n);
    rep(i, m) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--; v--;
        g[u].push_back({v, c});
    }
    vector<bool> is_ok(n);
    auto dfs = [&](auto self, int v, int cnt, ll cost) {
        if (cnt == l) {
            if (s <= cost && cost <= t) {
                is_ok[v] = true;
            }
            return;
        }
        for (auto [nv, ncost] : g[v]) {
            self(self, nv, cnt + 1, cost + ncost);
        }
    };
    dfs(dfs, 0, 0, 0);
    bool first = true;
    rep(i, n) {
        if (!is_ok[i]) continue;
        if (!first) cout << ' ';
        first = false;
        cout << i + 1;
    }
    cout << '\n';
    return 0;
}
