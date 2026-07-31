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
// 原因：答えの数え方を間違っていた
// j - i = Ai + Ajを変形してi + Ai = j - Ajの形にすることで左辺、右辺をそれぞれ計算することに
// 気付いたのは良かった。しかし、cnt[n]にi + Aiの計算結果もj - Ajの計算結果を入れたのはまずかった
// なぜならi + A[i] = kを満たすiが{i1, i2}の2個、j - A[j] = kが満たすjが{j1, j2, j3}の3個あるとき、
// i + A[i] = j - A[j]を満たすペア(i, j)はこの２つの集合から１個ずつ選ぶ全ての組み合わせだから
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> cnt_a(n);
    rep(i, n) {
        if (i + a[i] < n) cnt_a[i + a[i]]++;
    }
    vector<int> cnt_b(n);
    for (int j = 1; j < n; j++) {
        if (j >= a[j]) cnt_b[j - a[j]]++;
    }
    ll ans = 0;
    rep(i, n) ans += (ll)cnt_a[i] * cnt_b[i];
    cout << ans << "\n";
    return 0;
}
