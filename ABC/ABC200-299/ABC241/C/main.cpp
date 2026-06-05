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

    // #を見つける->縦横斜め全ての方角を6回移動して、3回#と出くわしたかカウント
    // 3回だったらYesで終了, Noだったら探索を続ける

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != '#') continue;
            for (int k = 0; k < 8; k++) {
                int cnt = 0;
                int y = i, x = j;
                int proceed = 0;
                // 現在の#の進む先とその反対方向に合計5個のブロックが置かれてるか調べたい
                for (int l = 0; l < 5; l++) {
                    int ny = y + dy[k], nx = x + dx[k];
                    if (ny < 0 || n <= ny || nx < 0 || n <= nx) break;
                    if (s[ny][nx] == '#') cnt++;
                    y = ny, x = nx;
                    proceed++;
                }
                if (proceed == 5 && cnt >= 3) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
