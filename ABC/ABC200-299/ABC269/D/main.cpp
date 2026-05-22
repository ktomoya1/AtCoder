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

// DFSの計算量：O(N) + マップ探索O(logN) = O(NlogN)
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    map<pair<int, int>, bool> seen;
    rep(i, N) {
        int y, x;
        cin >> y >> x;
        y--; x--;
        seen[{y, x}] = false;
    }

    const int di[6] = {-1, -1, 0, 0, 1, 1};
    const int dj[6] = {-1, 0, -1, 1, 0, 1};
    ll ans = 0;
    auto dfs = [&](auto self, int i, int j) -> void {
        seen[{i, j}] = true;
        for (int k = 0; k < 6; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (seen.find({ni, nj}) == seen.end()) continue;
            if (seen[{ni, nj}]) continue;
            self(self, ni, nj);
        }
    };
    for (auto [edge, k] : seen) {
        // インクリメントの方法がわからない
        int i = edge.first, j = edge.second;
        if (!seen[{i, j}]) {
            dfs(dfs, i, j);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
