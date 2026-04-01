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

    // タグ：メモ化再帰、map
    // 普通の再帰ではスタックオーバーフローする
    // オーバーフローの見落としに注意
    ll n;
    cin >> n;

    // メモ化するにもNの制限が大きすぎてメモリ制限超過する
    map<ll, ll> memo;
    auto dfs = [&](auto self, ll n) -> ll {
        if (n == 1) return 0;
        if (memo.count(n)) return memo[n];
        ll sum = n;
        if (n % 2 == 0) {
            sum += 2 * self(self, n / 2);
        } else {
            sum += self(self, n / 2);
            sum += self(self, (n + 1) / 2);
        }
        return memo[n] = sum;
    };
    ll ans = dfs(dfs, n);
    cout << ans << "\n";
    return 0;
}
