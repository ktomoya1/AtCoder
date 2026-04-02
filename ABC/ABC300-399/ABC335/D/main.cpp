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

    // ## グリッドシミュレーション、方向配列
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2, vector<int>(n + 2, -2));
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (r == (n + 1) / 2 && c == (n + 1) / 2)
                a[r][c] = -3;
            else a[r][c] = -1;
        }
    }
    
    int r = 1, c = 0;
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int k = 0;
    int index = 1;
    while (true) {
        // 問題：方向転換 右かつ、先が-1じゃなかったら下方向に移動する
        cerr << "a[" << r << "][" << c << "]=" << a[r][c] << ", k=" << k << "\n";
        int nr = r + dr[k], nc = c + dc[k];
        if (a[nr][nc] == -3) break;
        else if (a[nr][nc] == -1) {
            r = nr; c = nc;
            a[r][c] = index;
            index++;
        } else k = (k + 1) % 4;
    }
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (c != 1) cout << ' ';
            if (a[r][c] == -3)
                cout << 'T';
            else cout << a[r][c];
        }
        cout << "\n";
    }
    return 0;
}
