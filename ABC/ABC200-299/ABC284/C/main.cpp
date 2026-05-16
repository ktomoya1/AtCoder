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

vector<int> P;

int find(int x) {
    if (P[x] < 0) return x;
    return P[x] = find(P[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (P[x] > P[y]) swap(x, y);
    P[x] += P[y];
    P[y] = x;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    P.resize(N, -1);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        unite(x, y);
    }
    vector<bool> is_root(N);
    int ans = 0;
    rep(i, N) {
        int x = find(i);
        if (is_root[x]) continue;
        is_root[x] = true;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
