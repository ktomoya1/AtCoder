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

    // AC
    // 普通に差分を取ればいいのでは？
    int N, Q;
    cin >> N >> Q;
    // 現在の巣iに何匹いるか
    vector<int> H(N, 1);
    // 鳩iが現在どの巣にいるのかを保持しなくてはならない
    vector<int> P(N);
    // rep(i, N) P[i] = i;の代わりに
    iota(P.begin(), P.end(), 0);
    int ans = 0;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, h;
            cin >> p >> h;
            p--; h--;
            // p番目のはとを巣hに移動させる
            // P[p]はp番目の鳩がいる巣の番号
            int current_pos = P[p];
            int next_pos = h;
            // 減らす前に確認する
            H[current_pos]--;
            if (H[current_pos] == 1)
                ans--;
            H[next_pos]++;
            if (H[next_pos] == 2)
                ans++;
            P[p] = h;
        } else cout << ans << "\n";
    }
    return 0;
}
