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

// 解説AC
// 原因：DPで解こうとした->解けなくはないが、今回の中心拡張法よりは使いづらい解法
// なぜなら、今回は文字が一回だけ違っても無視できる条件があって、それが区間全体を
// 計算するdpは打ち切りの恩恵を得られず実装しづらいから
// 今回は「不一致ペア数のカウント」という単純集計問題であり、
// 選択を伴わないため、そもそもDPの複雑さが不要だった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    // kを動かすことで奇数長と偶数長の文字列をまとめる
    rep(k, 2) {
        rep(i, n) {
            int l = i - k, r = i;
            int cnt = 0;
            while (0 <= l && r < n) {
                if (s[l] != s[r]) cnt++;
                if (cnt > 1) break;
                l--; r++;
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
