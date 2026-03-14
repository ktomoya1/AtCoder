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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // 座標圧縮
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    // unique(vals.begin(), vals.end())は重複した要素の先頭位置のイテレータを返す
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int &x : a) {
        // aの要素がvalsの先頭からどれくらい離れているかを返す
        x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    }

    vector<int> count(n, 0);
    vector<bool> ans(n, false);
    int dup_cnt = 0;
    auto dfs = [&](auto self, int v, int pv) -> void {
        int del = 0;
        if (count[a[v]]) del = 1;
        dup_cnt += del;
        ++count[a[v]];
        if (dup_cnt) ans[v] = true;
        for (auto nx : g[v]) {
            if (nx == pv) continue;
            self(self, nx, v);
        }
        --count[a[v]];
        dup_cnt -= del;
    };
    
    dfs(dfs, 0, -1);
    rep(i, n) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
