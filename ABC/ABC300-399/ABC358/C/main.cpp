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

    // n: ポップコーン売り場の個数
    // m: ポップコーンの種類
    // si: i番目のポップコーン売り場でどの種類のものが売られているかの文字列
    // oは売ってる、xは売ってない
    // 制約から、全探索いけそう？→bit全探索よりはdfsの方がやりやすそう？
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<int> flags(n);
    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == 'o') {
                flags[i] |= (1 << (m - j - 1));
            }
        }
    }

    int ans = 2e9;
    for (int bit = 1; bit < (1 << n); ++bit) {
        int flag_ok = 0;
        int cnt = 0;
        for (int digits = 0; digits < n; ++digits) {
            if (bit & (1 << digits)) {
                flag_ok |= flags[digits];
                cnt++;
            }
        }
        if (flag_ok == (1 << m) - 1)
            ans = min(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}
