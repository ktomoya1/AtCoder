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

    int N, Q;
    cin >> N >> Q;

    // Aの最大値が10^6なので、それが入る配列を用意
    const int MAX_V = 1000005;

    // cnt[v] : 値がvであるティーバッグの山がいくつあるか
    vector<ll> cnt(MAX_V, 0);
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    // 累積和を作る
    // SumCnt[x] : 値がx以下の個数
    // SumVal[x] : 値がx以下の山の、ティーバッグ総数
    vector<ll> SumCnt(MAX_V, 0);
    vector<ll> SumVal(MAX_V, 0);

    for (int i = 1; i < MAX_V; i++) {
        SumCnt[i] = SumCnt[i - 1] + cnt[i];
        SumVal[i] = SumVal[i - 1] + (cnt[i] * i);
    }

    // クエリ処理
    for (int j = 0; j < Q; j++) {
        ll B;
        cin >> B;
        ll X = B - 1; // ディーラーの限界ライン（セーフライン）
        
        // Xが最大値を超えていたら、全部在庫の限界が来るだけ
        if (X >= MAX_V - 1) X = MAX_V - 1;

        // 小さい山グループ（全取り）の合計
        ll small_sum = SumVal[X];

        // 大きい山グループ（個数 * 上限X）
        // （全体の個数N）- （X以下の個数SumCnt[x]）= Xより大きい個数
        ll large_count = N - SumCnt[X];
        ll large_sum = large_count * X;

        ll ans = small_sum + large_sum + 1;

        // もし合計値を超えていたら -1（不可能）
        ll total_sum = SumVal[MAX_V - 1];
        if (ans > total_sum) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
