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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 最終ゴール：2 yの時にy個以上のブロックが積まれているマスの個数を出力したい
    // -> 1以上、2以上、3以上...のようなデータ型を作る
    // 全てのマスに１個以上ブロックが入ってるか確認するのにsetが欲しい
    // 問題は全てのマスからブロックを１個ずつ取り除く、これが厄介
    // O(1)で全てのマスからブロックを１個取り除く方法が思いつかない
    int N, Q;
    cin >> N >> Q;
    // 1以上、2以上、3以上...のデータ型
    // or_moreにoffsetがプラスされる可能性を考慮して3e5+10ではなく、3e6に変更->AC
    vector<int> or_more(3e5 * 2 + 10);
    // 現在の数字にブロックが何個積まれているかのデータ型
    vector<int> count(N);
    // 全てのブロックをO(1)で取り除くのが難しい->offsetで管理
    int offset = 0;
    or_more[0] = N;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            x--;
            // どうやって現在の数字が何個あるか確認する？->データ型が必要
            count[x]++;
            or_more[count[x]]++;
            if (or_more[1 + offset] == N)
                offset++;
        } else {
            int y;
            cin >> y;
            cout << or_more[y + offset] << "\n";
        }
    }
    return 0;
}
