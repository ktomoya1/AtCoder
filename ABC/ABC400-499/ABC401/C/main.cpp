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

    // Kから左の要素は1 * K
    // Kから右の要素は累積和で表せるか？
    // いや、普通に再帰で解けそう
    // 解けるけどTLEになる
    // 同じ数字を何回も再帰で計算しているのが無駄
    // 解法：メモ化再帰ってやつ？
    int N, K;
    cin >> N >> K;
    vector<ll> A(N + 1, 1);
    const ll MOD = 1e9;
    ll sum = K % MOD;
    for (int i = K; i <= N; i++) {
        A[i] = sum;
        sum = (sum + A[i]) % MOD;
        sum = (sum - A[i - K] + MOD) % MOD;
    }
    cout << A[N] % MOD << "\n";
    return 0;
}
