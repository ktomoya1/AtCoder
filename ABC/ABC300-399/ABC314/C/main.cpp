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

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }

    // dequeueを使ったやり方
    // push_frontやpop_back, pop_frontが重い
    [[maybe_unused]] auto solve_deque = [&]() {
        vector<deque<int>> color(m);
        rep(i, n) color[c[i]].push_back(i);
        rep(i, m) {
            color[i].push_front(color[i].back());
            color[i].pop_back();
        }
        string t = "";
        rep(i, n) {
            int idx = color[c[i]].front();
            t += s[idx];
            color[c[i]].pop_front();
        }
        cout << t << "\n";
    };

    // インデックスの余りを利用する方法
    auto solve_mod = [&]() {
        vector<vector<int>> color(m);
        rep(i, n) color[c[i]].push_back(i);
        string t = s;
        rep(i, m) {
            int k = color[i].size();
            rep(j, k) {
                // color[i] = [p0, p1, p2, ..., pk-1]に対して
                // t[p0] <- s[pk-1], t[p1] <- s[p0], t[p2] <- s[p1]
                //t[color[i][j]] = s[color[i][(j - 1 + k) % k]];

                // s[p0] -> t[p1], s[p1] -> t[p2], ..., s[pk-1] -> t[p0]
                t[color[i][(j + 1) % k]] = s[color[i][j]];
            }
        }
        cout << t << "\n";
    };

    // solve_deque();
    solve_mod();
    return 0;
}
