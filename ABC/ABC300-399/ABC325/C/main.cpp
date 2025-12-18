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

int H, W;
vector<string> S;

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x) {
    S[y][x] = '.';

    rep(i, 8) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < H && ny >= 0 && nx < W && nx >= 0 && S[ny][nx] == '#')
            dfs(ny, nx);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    S.resize(H);
    rep(i, H) cin >> S[i];

    int count = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                count++;
                dfs(i, j);
            }
        }
    }
    cout << count << endl;
    return 0;
}
