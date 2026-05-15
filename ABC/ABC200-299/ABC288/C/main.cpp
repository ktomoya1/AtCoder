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

// 解けなかった原因：DFSで平路を数えると2回カウントされることに気づかなかった
// 対処：DFSをトレースしてansがいくつになるか数える
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll ans = 0;
    vector<bool> seen(N);
    auto dfs = [&](auto self, int v, int parent) -> void {
        seen[v] = true;
        for (int nv : g[v]) {
            // 親に逆戻りするのはNG
            if (nv == parent) continue;
            if (seen[nv]) {
                ans++;
                continue;
            }
            self(self, nv, v);
        }
    };
    // 非連結グラフに対応するためのループ
    rep(i, N) {
        if (!seen[i])
            dfs(dfs, i, -1);
    }
    // 0->1->2->0と最後0に戻った後の0->2(seenはtrue)で合計２本、
    // つまり、一個の閉路でansは2増えてしまうため、2で割る
    ans /= 2;
    cout << ans << "\n";
    return 0;
}
