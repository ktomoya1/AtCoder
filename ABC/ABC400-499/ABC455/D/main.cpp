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
    vector<int> c(q), p(q);
    rep(i, q) cin >> c[i] >> p[i];

//    連結リストの解き方
    // auto linked_list = [&]() -> void {
    //     vector<int> up(n + 1), down(n + 1);
    //     rep(i, q) {
    //         // 現在の数字の上下は、どの数字かを管理するもの
    //         int x = down[c[i]];
    //         up[x] = 0;
    //         down[c[i]] = p[i];
    //         up[p[i]] = c[i];
    //     }
    //     for (int i = 1; i <= n; i++) {
    //         if (down[i]) {
    //             cout << 0 << " \n"[i == n];
    //             continue;
    //         }
    //         int x = i, cnt = 0;
    //         while (x) {
    //             x = up[x];
    //             cnt++;
    //         }
    //         cout << cnt << " \n"[i == n];
    //     }
    // };

//    Union-Findの解き方O((N + Q)・α(N))
    auto union_find = [&]() -> void {
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        cerr << "parent[5]:" << parent[5] << "\n";

        // parent[x] = self(self, parent[x]): xの親の親まで辿って、それを保持する
        // これをしないとO(NQ)になりTLE
        auto find = [&](auto& self, int x) -> int {
            return parent[x] == x ? x : parent[x] = self(self, parent[x]);
        };
        rep(i, q) parent[c[i]] = p[i];
        vector<int> size(n + 1);
        for (int i = 1; i <= n; i++) size[find(find, i)]++;
        for (int i = 1; i <= n; i++) cout << size[i] << " \n"[i == n];
    };


    // linked_list();
    union_find();
    return 0;
}
