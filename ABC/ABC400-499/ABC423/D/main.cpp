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

    // 典型的な待ち行列の問題、管理する変数が多すぎる
    // 退店時刻 <= 今の時刻になってるグループを取り出し、店内の人数を減らす。
    // 今の店内の人数＋新しい団体の人数<= Kなら新しい団体を入れる
    // もし、Kを超えていたら、先頭のキューを取り出し、その人が帰る時刻まで時間を進める。
    // 入店処理：
    // 入店時刻：max(到着した時刻＋席が空いた時刻)
    // 退店予定：入店時刻＋滞在時間(Bi)
    // キューに退店予定を入れて、店内の人数を増やす
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N), C(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i];

    // 優先度つきキュー
    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;
    ll current_people = 0;
    ll last_entry_time = 0;
    for (int i = 0; i < N; i++) {
        ll entry_time = max(A[i], last_entry_time);
        // 到着した時点(A[i])で、すでに帰っている人を追い出す
        while (!pq.empty() && pq.top().first <= entry_time) {
            current_people -= pq.top().second;
            pq.pop();
        }
        // それでも満席なら、空くまで時間を進める
        while (current_people + C[i] > K) {
            // 一番早く帰る団体を取り出す
            P p = pq.top();
            pq.pop();
            // 一番早く帰る団体まで、時間を進める
            // 帰るのが早すぎたら、本来の時間に入店できる
            entry_time = max(entry_time, p.first);
            current_people -= p.second;
        }
        cout << entry_time << "\n";

        pq.push({entry_time + B[i], C[i]});
        current_people += C[i];

        last_entry_time = entry_time;
    }
    return 0;
}
