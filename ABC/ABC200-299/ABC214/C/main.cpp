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

// ACだけどたまたま：更新した後にもう一周更新される可能性があるので２周する
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Si: i番目の人が宝石をもらってからi+1番目の人に渡すまでの時間
    // Ti: i番目の人に宝石を渡す時刻
    // まずans[i]はT[i]で初期化する
    // min_idxを求めてその人から一周して時刻を数える
    // ans[(min_idx+i+1) % N] = ans[(min_idx + i) % N] + S[(min_idx + i) % N]
    // 既存の最小値と比較するので、
    // ans[(min_idx+i+1) % N] = min(ans[(min_idx + i) % N], ans[(min_idx + i) % N] + S[(min_idx + i) % N])
    // ans[i]はt[i]で代用できるし、minを使えばmin_idxを求める必要もない
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    rep(i, 2*n) {
        t[(i + 1) % n] = min(t[(i + 1) % n], t[i % n] + s[i % n]);
    }
    rep(i, n) cout << t[i] << "\n";
    return 0;
}
