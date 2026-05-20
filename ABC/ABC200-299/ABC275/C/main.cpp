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

// 間違えた原因：2点から正方形の残り２頂点を求めるという発想と、そのための90度回転の計算が頭になかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> S(9);
    rep(i, 9) cin >> S[i];

    vector<pair<int, int>> sharp_pos;
    rep(i, 9) {
        rep(j, 9) {
            if (S[i][j] == '#') sharp_pos.push_back({i, j});
        }
    }

    int N = sharp_pos.size();
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            auto [r1, c1] = sharp_pos[i];
            auto [r2, c2] = sharp_pos[j];

            int dr = r2 - r1;
            int dc = c2 - c1;

            int r3 = r1 - dc, c3 = c1 + dr;
            int r4 = r2 - dc, c4 = c2 + dr;
            if (r3 < 0 || r3 >= 9 || c3 < 0 || c3 >= 9) continue;
            if (r4 < 0 || r4 >= 9 || c4 < 0 || c4 >= 9) continue;

            if (S[r3][c3] == '#' && S[r4][c4] == '#') {
                ans++;
            }
        }
    }
    // ABは計算するが、BAは計算しない
    cout << ans / 2 << "\n";
    return 0;
}
