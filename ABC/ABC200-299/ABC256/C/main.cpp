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

// 間違えた原因：for文でループさせる自由変数を決めなかった＋条件の列挙漏れ
// 実装前に制約を全部列挙->どの制約がループで自動保証され、どれが要チェックか仕分ける
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 2マス決まればもう一マスは自ずと決まる
    int h[3], w[3];
    cin >> h[0] >> h[1] >> h[2] >> w[0] >> w[1] >> w[2];

    int ans = 0;
    vector<vector<int>> a(3, vector<int>(3));
    for (int a00 = 1; a00 <= 28; a00++) {
        for (int a01 = 1; a01 <= 28; a01++) {
            for (int a10 = 1; a10 <= 28; a10++) {
                for (int a11 = 1; a11 <= 28; a11++) {
                    // 残りの変数を決める
                    a[0][0] = a00, a[0][1] = a01;
                    a[1][0] = a10, a[1][1] = a11;
                    a[0][2] = h[0] - a00 - a01,
                    a[1][2] = h[1] - a10 - a11,
                    a[2][0] = w[0] - a00 - a10,
                    a[2][1] = w[1] - a01 - a11,
                    a[2][2] = w[2] - a[0][2] - a[1][2];
                    if (min({a[0][2], a[1][2], a[2][0], a[2][1], a[2][2]}) > 0
                        && a[2][0] + a[2][1] + a[2][2] == h[2]) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
