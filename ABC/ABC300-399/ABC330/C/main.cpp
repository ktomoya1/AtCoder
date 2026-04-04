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

    // ## 全探索、変数固定、尺取り法
    // まず、x, yで全探索で解いてみる
    // なんの工夫もせずに全探索をするとTLEになるので、範囲を絞ろう
    // <ミス>しかし、x, yをどの範囲で動かせばいいかわからない
    // |x^2 + y^2 - D|が0付近が理想->x^2 >= Dになるギリギリまでがいい
    // つまり、x < √Dがよいが、x = 2, y = 0, D = 3などのケースが漏れる可能性がある
    // そのため、0 <= x, y <= √D + 1
    // 1 <= D <= 2e12より、0 <= x, y <= 2e6 + 1
    // ここで、xを固定したとき、y = √(D - x^2)
    // 弧に一番近い点はどこっていう問題
    // xを増やして円弧をはみ出した時、yを減らして弧に近づけるイメージ
    // 二分探索使えそうじゃない？-> Dの制約が大きいから厳しそう
    ll d;
    cin >> d;
    ll ans = d; // 答えはdより大きくならない
    ll y = 2e6;
    for (ll x = 0; x <= 2e6; x++) {
        // xを増やしていくと、x^2の値はどんどん大きくなるため、y^2は必ず減る方向に動かす
        while (y > 0 && x * x + y * y > d) y--; // 最低y = 0まで減らす
        // この時点でx * x + y * y はD内（円の中）に入っている
        ans = min(ans, abs(x * x + y * y - d));
        // y + 1をすることで円を少しはみ出した位置での距離を測る
        ans = min(ans, abs(x * x + (y + 1) * (y + 1) - d));
    }
    cout << ans << "\n";
    return 0;
}

// // yの探索に二分探索を使う方法
// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     ll d;
//     cin >> d;
//
//     ll ans = d;
//     for (ll x = 0; x <= 2e6; x++) {
//         // 探索対象の値を割り出す
//         ll target = d - x * x;
//         // すでにx^2だけでdを超えている場合
//         if (target <= 0) {
//             ans = min(ans, abs(x * x - d));
//             continue;
//         }
//
//         ll ok = 0;
//         ll ng = 2e6;
//         while (abs(ok - ng) > 1) {
//             ll mid = (ok + ng) / 2;
//             if (mid * mid <= target)
//                 ok = mid;
//             else
//                 ng = mid;
//         }
//         ans = min(ans, abs(x * x + ok * ok - d));
//         ans = min(ans, abs(x * x + ng * ng - d));
//     }
//     cout << ans << "\n";
//     return 0;
// }
