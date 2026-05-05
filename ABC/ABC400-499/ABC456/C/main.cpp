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
#include <unistd.h>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ## 極大区間
    // 間違えた原因：数える範囲が漏れてた
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;

    // 組み合わせの方法
    // int l = 0, r = 0;
    // while (l < n) {
    //     while (r < n - 1 && s[r] != s[r + 1]) {
    //         r++;
    //     }
    //     r++;
    //     // Lをintにするとオーバーフローする
    //     // Lの最大値は3*10^5なので、(3*10^5 + 1) * 3*10^5 ≒ 9*10^10
    //     ll L = r - l;
    //     ans += (L + 1) * L / 2;
    //     l = r;
    // }

    // 右側を固定する方法
    // 汎用的に使える条件：
    // 部分文字列・部分配列の個数を数える
    // 「条件違反が起きた位置だけ覚えれば十分か」
    int prv = -1;
    for (int i = 0; i < n; i++) {
        ans += i - prv;
        if (i + 1 < n && s[i] == s[i + 1]) prv = i;
    }
    cout << ans % 998244353 << "\n";
    return 0;
}
