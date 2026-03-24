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

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    queue<pair<int, int>> q;
    const int dr[4] = {-1, 0, 0, 1};
    const int dc[4] = {0, -1, 1, 0};
    ll ans = 0;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (s[r][c] == '#' || seen[r][c]) continue; 
            seen[r][c] = true;
            q.push({r, c});
            bool is_outer = false;
            while (!q.empty()) {
                auto [rr, cc] = q.front();
                q.pop();
                if (rr == 0 || rr == h - 1 || cc == 0 || cc == w - 1)
                    is_outer = true;
                for (int i = 0; i < 4; i++) {
                    int nr = rr + dr[i], nc = cc + dc[i];
                    if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                    if (s[nr][nc] == '#' || seen[nr][nc]) continue;
                    seen[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            if (!is_outer) ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
