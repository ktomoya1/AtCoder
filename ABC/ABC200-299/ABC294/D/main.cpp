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

    // 間違えた原因：問題の読み違い
    // イベント3で「再度呼ばれる」を「呼ばれて受付に行く」と無意識に読んだのがダメだった
    // 状態遷移問題では、各イベントが「どの遷移矢印を動かすか」だけを先に図時してから実装する
    int n, q;
    cin >> n >> q;
    // setによる管理の方法O(logN)
    // set<int> is_called;
    // vector<bool> is_accepted(n + 1, false);
    // int id = 1;
    // while (q--) {
    //     int t;
    //     cin >> t;
    //     if (t == 1) {
    //         // 呼ばれてない番号のうち、最小値を選ぶ
    //         is_called.insert(id);
    //         ++id;
    //     } else if (t == 2) {
    //         int x;
    //         cin >> x;
    //         if (is_accepted[x]) continue;
    //         is_called.erase(x);
    //         is_accepted[x] = true;
    //     } else {
    //         cout << *is_called.begin() << "\n";
    //     }
    // }

    // ２つのポインタによる解法O(N + Q)
    // 1. 最小値が単調増加することに気づく
    // 2. setが必要な理由は「最小値が変動するとき」
    // 要素の追加・削除で最小値が下がる可能性があるとき、常に全体を管理する必要がある
    // setはそのためにある
    // 3. 単調増加なら最小値は今の位置より左に戻らない。つまり、ポインタより左を見る必要が
    // なく、今どこまで見たかを記録するポインタ１本で十分になる
    vector<char> s(n + 1);
    // minは次に呼び出される最小番号
    // min2は次に出力される呼び出し済み未受付の人の最初番号
    int min = 1, min2 = 1;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            // 未受付で呼ばれていない人のうち、最小番号の人を選び、呼び出し済みにする
            s[min] = 1;
            while (s[++min] >= 1);
        } else if (t == 2) {
            // 呼び出し済みの人xを受付済みにする
            int x;
            cin >> x;
            s[x] = 2;
            // もしxがmin2だったら次の呼び出し済み未受付の人を探す
            if (x == min2) while (s[++min2] == 2);
            // xが最小値じゃなければ、min2は更新しなくてよい
        } else {
            // 呼び出し済み未受付の人のうち、最小番号の人を出力する
            cout << min2 << "\n";
        }
    }
    return 0;
}
