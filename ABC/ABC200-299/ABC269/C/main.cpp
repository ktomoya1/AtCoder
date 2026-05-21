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

// O(N)だとTLEだからO(logN)とかO(1)じゃないと厳しい
// 間違えた原因：O(N)がTLEだからO(logN)かO(1)が必要という思い込みで、O(2^k)という正しい計算量
// に気付けなかったこと
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    // xより次に小さい、nの部分集合を(x - 1) & nで取ってこれる
    for (ll x = n; ; x = (x - 1) & n) {
        cout << (n ^ x) << '\n';
        if (x == 0) break;
    }
    return 0;
}
