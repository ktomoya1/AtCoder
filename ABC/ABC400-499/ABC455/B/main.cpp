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
    int ans = 0;
    rep(h1, h) {
        for (int h2 = h1; h2 < h; h2++) {
            rep(w1, w) {
                for (int w2 = w1; w2 < w; w2++) {
                    bool flag = true;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            if (s[i][j] != s[h1 + h2 - i][w1 + w2 - j]) flag = false;
                        }
                    }
                    if (flag) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
