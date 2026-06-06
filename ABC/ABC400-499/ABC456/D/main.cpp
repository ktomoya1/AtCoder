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
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// 解説AC、解けなかった原因：知らないパターン
// ゴール：部分列の個数を求める
// 問題：全部列挙すると指数的に多い->直接数えるのはNG
// ステップ1：文字をひとつずつ追加していく方針を考える->「今までの部分列にi番目の文字を追加する」
//      　     操作を繰り返せば全部列挙できる->ここでダメだった
// ステップ2：追加できるかどうかは何に依存するか->直前の文字だけ。それ以前の情報は不要
// ステップ3：直前の文字ごとに個数を管理すればいい->dp[直前の文字]=個数
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int m = 998244353;
    string s;
    cin >> s;

    // dp[i][x]: sのi文字目までからなる部分列のうち、末尾がx(a, b, c)であるものの個数
    vector<ll> dp(3);
    int n = s.size();
    rep(i, n) {
        int x = s[i] - 'a';
        dp[x] = dp[0] + dp[1] + dp[2] + 1;
        dp[x] %= m;
    }
    ll ans = 0;
    rep(i, 3) {
        ans += dp[i];
        ans %= m;
    }
    cout << ans << "\n";
    return 0;
}
