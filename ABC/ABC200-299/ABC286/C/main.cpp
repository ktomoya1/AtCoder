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

// 間違えた原因：難しく考えすぎ
// 無駄な探索を省く前に全探索が通るか確認するべきだった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    // 文字列の大きさに余裕があれば文字連結でoffset計算をなくす
    S += S;
    ll ans = 9e18;
    for (int i = 0; i < N; i++) {
        ll t = i * A;
        for (int j = 0; j < N / 2; j++) {
            t += B * (S[i + j] != S[N - 1 - j + i]);
        }
        ans = min(ans, t);
    }
    cout << ans << "\n";
    return 0;
}
