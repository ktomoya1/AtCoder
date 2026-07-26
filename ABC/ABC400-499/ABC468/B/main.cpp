#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// ACだが2回ペナルティ
// 原因：外側ループをd~m-dに絞ったこと
// d未満、m-d以上、つまり左端、右端付近のGが無視される
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, d;
    string s;
    cin >> m >> d >> s;
    vector<bool> is_ok(m, false);
    for (int i = 0; i < m; i++) {
        if (s[i] != 'G') continue;
        int l = max(0, i - d), r = min(m - 1, i + d);
        for (int x = l; x <= r; x++) is_ok[x] = true;
    }
    int ans = 0;
    rep(i, m) {
        if (!is_ok[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
