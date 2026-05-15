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

vector<int> parent;

// find(x): xが属するグループの根を返す
int find(int x) {
    if (parent[x] < 0) return x;
    // x != parent[x]->親を辿る
    // parent[find(x)]は無限再帰
    // return find(parent[x])では毎回根まで全部辿るからTLE
    // 経路圧縮
    return parent[x] = find(parent[x]);
}

// unite(x, y): xとyを同じグループにする
bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (parent[x] > parent[y]) swap(x, y);
    parent[x] += parent[y]; // xの木のサイズにyが属する木のサイズを足す
    parent[y] = x;
    return true;
}

// 辺を削除する最小数->閉路一個につき、一本削除する->閉路の数を数える
// ->閉路か判定するタイミングは起点と終点が繋がるとき
// ->起点と終点が同じグループであるべき
// ->グループ管理ができるUnion-Findを使う
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    parent.resize(N, -1);
    int ans = 0;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (!unite(a, b)) ans++;
    }
    cout << ans << "\n";
    return 0;
}
