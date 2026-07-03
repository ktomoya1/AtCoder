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

// WAの原因：最大値から水の個数分抜くのはいいが、その後に小さいものから飲んで行ったこと
// 最小個数を選ぶ→できるだけ多い量を飲みたい
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 酒の数：K、水の数：N-K
    // 最低なんこのカップを選ぶ必要があるか->最悪の選び方をする
    // ->昇順に並べてN-K個の水を飲んだ(最大値をpushback)後に酒を最小値から飲んでいき、XmLを超えた時の数
    // XmLを超えなかったら-1
    // 最悪の選び方をするだけではだめ→最高の選び方をしたい
    // 最大値側に酒が集まってる時、の最小数を求めたい
    int n, k; ll x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.rbegin(), a.rend());

    int ans = 0;
    ll a_sum = 0;
    rep(i, n) {
        ans++;
        if (i < n - k) continue;
        a_sum += a[i];
        if (a_sum >= x) break;
    }
    cout << (a_sum >= x ? ans : -1) << "\n";
    return 0;
}
