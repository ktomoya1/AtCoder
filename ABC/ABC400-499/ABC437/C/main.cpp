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

void solve() {
    int N;
    cin >> N;
    vector<ll> W(N), P(N);
    rep(i, N) cin >> W[i] >> P[i];

    // 2. 全員の「重さの合計 (total_weight)」を計算する
    // ?　なんでtotal_weightを計算するの？
    // これが、チーム全体で支えなければならない目標値になります
    ll total_weight = 0;
    rep(i, N) total_weight += W[i];

    // 3.  各トナカイの「評価値 (P + W)」を格納する配列を作る
    // 配列名例: scores
    // logic: ソリから降りて引く側に回ると、「自分の重さ(W)が消え」かつ「自分の力(P)が増える」
    // つまり、チームの状況が (P + W) だけ改善します
    vector<ll> scores(N, 0);
    rep(i, N) scores[i] += W[i] + P[i];

    // 4. 評価値が大きい順（降順）にソートする
    // ヒント: sort(scores.rbegin(), scores.rend()); を使うと一発で降順になります
    sort(scores.rbegin(), scores.rend());

    // 5. 貪欲法：条件を満たすまで、上から順に「引く係」を選んでいく
    // current_power (現在のチームの底力) に評価値を足していき、
    // total_weight 以上になったらループを抜ける
    ll current_power = 0;
    int num = 0;
    for (int i = 0; i < N; i++) {
        current_power += scores[i];
        num++;
        if (current_power >= total_weight)
            break;
    }

    // 6. 答えを出力
    // 求めたいのは「乗れる人数」なので、 (N - 引く人数) を出力
    // 改行 ("\n") を忘れずに
    cout << N - num << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve(); 
    }
    return 0;
}
