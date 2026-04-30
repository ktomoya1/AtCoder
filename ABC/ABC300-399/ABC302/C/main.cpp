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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ## next_permutaiton, 再帰
    // next_permutationを使うには->順番を全部試したいと気づく
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    // // next_permutationの方法
    // sort(s.begin(), s.end()); // sortをすることで一部の組み合わせを飛ばさない
    // do {
    //     bool ok = true;
    //     rep(i, n - 1) {
    //         int wrong_cnt = 0;
    //         rep(j, m) {
    //             if (s[i][j] != s[i + 1][j]) wrong_cnt++;
    //         }
    //         if (wrong_cnt != 1) ok = false;
    //     }
    //     if (ok) {
    //         cout << "Yes\n";
    //         return 0;
    //     }
    // } while (next_permutation(s.begin(), s.end()));
    // cout << "No\n";

    // DFSの方法
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        rep2(j, i + 1, n) {
            int wrong_cnt = 0;
            rep(k, m) {
                if (s[i][k] != s[j][k]) wrong_cnt++;
            }
            if (wrong_cnt == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<bool> seen(n);
    auto dfs = [&](this auto self, int v, int path_len) -> bool {
        seen[v] = true;
        if (path_len == n) return true;
        for (auto nv: g[v]) {
            if (seen[nv]) continue;
            if (self(nv, path_len + 1)) return true;
        }
        seen[v] = false;
        return false;
    };

    bool ok = false;
    rep(i, n) {
        if (dfs(i, 1)) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";

    return 0;
}
