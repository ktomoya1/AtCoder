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

    // N個のシャリ, M個のネタ
    // Ai: シャリの重さ、Bj: ネタの重さ
    // ネタの重さはシャリの重さの２倍以下でなければならない
    // Bj <= Ai * 2
    // 作ることのできる寿司の個数の最大値を求めよ
    // シャリが小さい時、
    // AiとBjをソートする->iとjで上の不等式を計算していく、上の条件を満たす=count++
    // シャリを動かすのが内側ループ
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0; // jは外側、iは内側
    ll ans = 0;
    while (i < n && j < m) {
        while (i < n && a[i] * 2 < b[j]) i++;
        if (i < n && a[i] * 2 >= b[j]) {
            i++;
            ans++;
        }
        j++;
    }
    cout << ans << "\n";
    return 0;
}
