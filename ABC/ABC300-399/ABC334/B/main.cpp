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

// x以下で一番東の木の番号を返す
ll f(ll x, ll m) {
    // rはxをmで割った余り->xがmの倍数からどれだけはみ出しているか
    // xが負の場合、x % mは-(m - 1)~0の値に収まり、mを足せば正の値の正しい余りになる
    // (x % m + m) % mをしているのは、xが正の場合、x % m + mがm以上になるのを防ぐため
    ll r = (x % m + m) % m;
    // x - r: rだけはみ出た分を引く
    // (x - r) / m: 0-indexで木が何番目にあるかを求める
    return (x - r) / m;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 典型テク：l, rが正の時、0~rの木の本数から0~l-1までの木の本数を減らすと求めやすい
    // なぜなら、0~rという範囲なら、r / mで簡単に求められるから
    // l, rが正、lが負、rが正、l, rが負の場合がある
    // 場合分けが面倒なので、l, rに大きい数を足して、どちらも正にする
    // なお、場合分けが不要になるfloor関数を作っているため、無問題
    // 工夫：aを原点にした方がわかりやすい。aを引いて、aを0にする
    // 工夫：(0~r) - (0~l-1)
    ll a, m, l, r;
    cin >> a >> m >> l >> r;

    // 木が立つ位置をa + kmからkmにする
    l -= a; r -= a;

    //  座標x以下の木は⌊x/M⌋ + 1本生える(+1は0-indexだから)
    //  (⌊r/M⌋ + 1) - ( ⌊l - 1/M⌋ + 1)
    cout << f(r, m) - f(l - 1, m) << "\n";
    return 0;
}
