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

    // ## 連結リスト
    // 1. 大量の要素をまとめて移動する可能性がある->素朴な実装はTLE
    // 2. 挿入先が常に端（一番上/一番下）に限定されている->つなぎ直しがO(1)ですむ
    // 3. 途中の状態ではなく、最終状態が必要->毎回全体を更新しなくていい
    // まとめると、「操作が局所的（端への挿入・切り離しだけ）で、最終状態だけ知りたい」なら
    // 連結リストが有効
    int n, q;
    cin >> n >> q;

    // 現在の数字の上下は、どの数字かを管理するもの
    vector<int> up(n + 1), down(n + 1);
    while (q--) {
        int c, p;
        cin >> c >> p;
        int x = down[c];
        // 変更箇所:移動させるカードの下のカードの上方向、
        up[x] = 0;
        // 移動先の一番上のカードの上方向、
        up[p] = c;
        // 移動させるカードの下方向
        down[c] = p;
    }
    for (int i = 1; i <= n; i++) {
        // 現在のカードの下が0でなければ、別の山の一部になっている。
        // つまり、山はないし、たどって行くとしても途中からになってしまう。
        if (down[i]) {
            cout << 0 << " \n"[i == n];
            continue;
        }
        // 逆に、現在のカードの下が0であれば、自身が山の底であり、上にたどっていけて、
        // 全てのカードを数え上げられる
        // 山が存在し続けるためにはカードiが一度もCiとして選ばれないことが条件
        int x = i, ans = 0;
        while (x) {
            ans++;
            x = up[x];
        }
        cout << ans << " \n"[i == n];
    }
    return 0;
}
