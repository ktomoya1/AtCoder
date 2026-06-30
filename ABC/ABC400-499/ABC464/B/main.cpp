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

// ACできたけど時間がかかった理由：愚直に実装したこと
// 「端から削る操作」-> 「黒ピクセルの境界を求める」に言い換えられることに気づくべきだった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    int u = h, d = -1;
    int l = w, r = -1;
    rep(i, h) {
        rep(j, w) {
            if (c[i][j] == '#') {
                u = min(u, i), d = max(d, i);
                l = min(l, j), r = max(r, j);
            }
        }
    }

    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}
