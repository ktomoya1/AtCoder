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

    int N, Q;
    cin >> N >> Q;

    // 番兵法（if文省略, 1-index_baseに合わせるため）
    vector<int> color(N + 2, 0);

    // O(NQ)はTLE
    int ans = 0;
    while (Q--) {
        int x;
        cin >> x;
        // 白の時
        if (color[x] == 0) {
            color[x] = 1;
            if (color[x - 1] == 0 && color[x + 1] == 0) ans++;
            else if (color[x - 1] == 1 && color[x + 1] == 1) ans--;
        } else {
            // 黒の時
            color[x] = 0;
            if (color[x - 1] == 0 && color[x + 1] == 0) ans--;
            else if (color[x - 1] == 1 && color[x + 1] == 1) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
