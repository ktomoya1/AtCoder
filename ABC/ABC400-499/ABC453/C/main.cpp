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

    int n;
    cin >> n;
    vector<ll> l(n);
    rep(i, n) cin >> l[i];

    // ## bit全探索, coutとcerrの出力時間
    // 原因：cerr, coutが時間かかったため、TLEになると思った
    // システムコール１回の呼び出し=10^-6（1~10マイクロ秒）
    // 今回の最大ループ回数：2^20 * 20 = 100万回 * 20 = 10^6 * 20 = 2 * 10^7
    // 合計時間：2 * 10^7 * 10^-6 = 20秒かかる
    ll ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        ll count = 0;
        ll x = 1;
        for (int digit = 0; digit < n; digit++) {
            ll sign = 1;
            if (bit & (1 << digit))
                sign = -1;
            ll result = x + 2 * sign * l[digit];
            if ((x > 0 && result < 0) || (x < 0 && result > 0))
                count++;
            x = result;
        }
        ans = max(ans, count);
    }
    cout << ans << "\n";
    return 0;
}
