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

// ゴール：各座標が何個の区間に含まれるかわかれば、0->非0と非0->0の境界を出力できる
// 問題：各座標の区間カウントをどう求めるか
// 素朴な方法：各区間[l, r)について座標l~r-1に+1。O(N*区間長)で遅い
// 高速化：「開始と終了だけ記録して、累積和で一括反映->imos法。O(N)
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> d(2e5 + 10);
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        d[l]++; d[r]--;
    }
    for (int i = 1; i <= 2e5; i++) d[i] += d[i - 1];
    for (int i = 1; i <= 2e5; i++) {
        if (!d[i - 1] && d[i]) cout << i << ' ';
        if (d[i - 1] && !d[i]) cout << i << '\n';
    }
    return 0;
}
