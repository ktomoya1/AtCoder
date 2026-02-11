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

    // いもす法を使いたい
    // WA: 桁上がりすることを考えると、出力する桁数がmax_numでは足りない、
    // 　　imos[i]に最大2*10^5入ることを想定できていなかった。
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    const int M = 200010;
    // 各桁の頻度を計算する
    vector<int> c(M);
    rep(i, n) c[a[i]]++;
    // 各桁の数字
    vector<int> d(M);
    int rem = n;
    rep(i, M) {
        rem -= c[i];
        d[i] = rem;
    }
    rep(i, M) {
        if (d[i] >= 10) {
            d[i + 1] += d[i] / 10;
            d[i] %= 10;
        }
    }
    // 最上位の桁より大きい桁は消す
    while (d.back() == 0) d.pop_back();
    reverse(d.begin(), d.end());
    for (int x : d) cout << x;
    cout << "\n";
}
