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

    // 変更箇所の左二文字と右二文字の差分を考える
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = string(2, '.') + s + string(2, '.');
    int ans = 0;
    for (int i = 0; i < n + 2; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
            ++ans;
    }
    while (q--) {
        int x;
        char c;
        cin >> x >> c;
        ++x;
        // 変更することで減る可能性
        for (int dx = -1; dx <= 1; ++dx) {
            int now = x + dx;
            if (s[now - 1] == 'A' && s[now] == 'B' && s[now + 1] == 'C')
                --ans;
            if ((dx == -1 && s[now - 1] == 'A' && s[now] == 'B' && c == 'C')
                || (dx == 0 && s[now - 1] == 'A' && c == 'B' && s[now + 1] == 'C')
                || (dx == 1 && c == 'A' && s[now] == 'B' && s[now + 1] == 'C'))
                ++ans;
        }
        s[x] = c;
        cout << ans << "\n";
    }
    return 0;
}
