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

// int N, X, Y;
// ll ans = 0;
// 
// void solve(char color, int level) {
//     if (color == 'b' && level >= 1) {
//         if (level == 1) {
//             ans++;
//             return;
//         } else {
//             // leveln以上の青い宝石は
//             // レベルn - 1の赤い宝石1個
//             solve('r', level - 1);
//             // レベルn - 1の青い宝石X個
//             rep(x, X) {
//                 solve('b', level - 1);
//             }
//         }
//     } else if (color == 'r' && level >= 1) {
//         if (level == 1)
//             return;
//         else {
//             // leveln以上の赤い宝石は
//             // レベルn - 1の赤い宝石1個
//             solve('r', level - 1);
//             // レベルnの青い宝石Y個に
//             rep(y, Y) {
//                 solve('b', level);
//             }
//         }
//     }
// }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N: レベル
    // X, Y: 変換される青い宝石の個数
    // 赤n→赤n-1 + 青X個
    // 青n→赤n-1 + 青Y個
    // 赤い宝石と青い宝石が両方無くなるまで続ける
    // レベル１の青い宝石は最大何個入手できる？
    // 再帰
    // [?]再帰の計算量はどうやって計算したの？

    int N, X, Y;
    cin >> N >> X >> Y;

//    solve('r', N);
//    cout << ans << "\n";

    // ？なんでDPを考えついた？
    // dp[i]: レベルiの宝石1個から得られるレベル１の青い宝石の数
    // red[i]: 赤い宝石用、blue[i]: 青い宝石用
    vector<ll> red(N + 1);
    vector<ll> blue(N + 1);

    blue[1] = 1; // 青1はそのまま1個
    red[1] = 0; // 赤1は何も産まない

    // 2. レベル2からNまで順番に計算
    for (int i = 2; i <= N; ++i) {
        // レベルiの青 -> レベルi-1の赤1個 + レベルi-1の青Y個
        blue[i] = red[i - 1] + blue[i - 1] * Y;
        // レベルiの赤 -> レベルi-1の赤1個 + レベルiの青X個
        // 今計算したばかりのblue[i]を使う
        // [?] なんでこの式になるのかわからない
        red[i] = red[i - 1] + blue[i] * X;
    }

    cout << red[N] << "\n";
    return 0;

}
