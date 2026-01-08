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

int N, M;
ll ans = 2e18; // 最小値を入れる時は大きい値にしておく
vector<vector<pair<int, ll>>> G;
vector<bool> seen;

void dfs(int u, ll val) {
    if (u == N - 1) {
        ans = min(ans, val);
        return;
    }

    // 一度見た道は通らない（ただし、別ルートではこの道を見ていないとする
    seen[u] = true;
    for (auto edge : G[u]) {
        int v = edge.first;
        ll w = edge.second;

        if (!seen[v]) {
            dfs(v, val ^ w);
        }
    }
    // 他のルートからアクセスするときに開けておく
    seen[u] = false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // グラフをまとめるのに適したデータ型ってなんだっけ？
    // ->本来はvector<vector<int>>だが、今回は重みがついてるので、vector<vector<pair<int, ll>>>
    // XORってどうやって計算するんだっけ？-> val ^ w
    cin >> N >> M;
    G.resize(N);
    rep(i, M) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        // 無向グラフはu->v, v->uの両方をプッシュする
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    seen.assign(N, false);
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}
