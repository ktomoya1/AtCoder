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

// ACしたけどペナルティ2回＋45分かかった
// WAの原因：最後のインデックスだけstart = a[i] + 100を省略する特別扱いをしたこと。
// 添え字の位置で状態遷移のルールを変えない、境界条件はループ外でまとめて処理する
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    int start = 0;
    ll ans = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a < start) continue;
        ans += a - start;
        start = a + 100;
    }
    if (start < t) ans += t - start;
    cout << ans << "\n";
    return 0;
}
