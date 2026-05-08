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

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// O(N√N)の解法
void solve(int n) {
    // 間違えた原因：cdの約数を1からcdまで線形探索していたこと
    // + cdだけじゃなくて、abも固定して考えるべきだった。
    ll ans = 0;
    for (int x = 1; x < n; ++x) {
        int ab = x, cd = n - x;
        ll ans1 = 0, ans2 = 0;
        for (int a = 1; a * a <= ab; ++a) {
            if (ab % a) continue;
            ++ans1;
            if (a * a != ab) ++ans1; // (3, 3)などの場合は数えない
        }
        for (int c = 1; c * c <= cd; ++c) {
            if (cd % c) continue;
            ++ans2;
            if (c * c != cd) ++ans2;
        }
        ans += ans1 * ans2;
    }
    cout << ans << "\n";
}

// O(NlogN)の解法
// 思考の流れ:
// num[v]=vの約数ペア数がほしい
// ->全vについてほしいなら、√vループを各vに対してやるより、「掛け算の結果を配列に積む」方が早い
// エラトステネスの篩と同じ発想
void solve2(int n) {
    vector<ll> num(n + 1);
    for (ll x = 1; x < n; ++x) {
        for (ll y = 1; x * y < n; ++y) {
            ++num[x * y];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += num[i] * num[n - i];
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    solve2(n);
    return 0;
}
