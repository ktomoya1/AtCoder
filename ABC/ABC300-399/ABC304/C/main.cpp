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

    // ## グラフ問題、DFS, BFS, Union-Find
    // 頂点：N人の人たち、辺：人iと人jの距離がD以下であるとき、辺(i, j)を張る
    // 問題：各人、その他のN - 1人の人と比較して感染しているか判断しなければならない
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<bool> is_sick(n, false);
    queue<int> q;
    is_sick[0] = true;
    q.push(0);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        rep(j, n) {
            // 病気じゃない人を探す
            if (i == j || is_sick[j]) continue;
            // powは浮動小数点演算なので、誤差が出る可能性がある
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist <= d * d) {
                is_sick[j]= true;
                q.push(j);
            }
        }
    }
    rep(i, n) {
        if (is_sick[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
