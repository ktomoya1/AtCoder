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

// bit全探索の方法
// 解くのに時間がかかった原因：誤読
// 条件を1 <= x <= N全てを持った集合Siが少なくとも一つ存在するという条件だと誤解した
// 対策：少なくとも1個存在する」の主語が何かを確認する習慣をつける
void solve(int N, int M, vector<int> S_bit) {
    ll ans = 0;
    // 外側ループは試す集合の組み合わせ
    for (int bit = 1; bit < (1 << M); ++bit) {
        // 内側ループは一つの集合に着目する
        int cover = 0;
        for (int digits = 0; digits < M; ++digits) {
            if (bit & (1 << digits)) {
                cover |= S_bit[digits];
            }
        }
        if (cover == (1 << N) - 1) ++ans;
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> S_bit(M);
    rep(i, M) {
        int c;
        cin >> c;
        rep(j, c) {
            int a;
            cin >> a;
            --a;
            S_bit[i] |= (1 << a);
        }
    }

    solve(N, M, S_bit);
    return 0;
}
