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

string T;
vector<string> S;

bool check(int y, int x, int N) {
    rep(i, N) {
        if (T[i] == 'L') x--;
        else if (T[i] == 'R') x++;
        else if (T[i] == 'U') y--;
        else y++;
        if (S[y][x] == '#') return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N;
    cin >> H >> W >> N;
    cin >> T;
    S.resize(H);
    rep(i, H) cin >> S[i];
    
    int ans = 0;
    // '.'を見つけるまでインクリメント
    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            if (S[i][j] == '.') {
                if (check(i, j, N) == true)
                    ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
