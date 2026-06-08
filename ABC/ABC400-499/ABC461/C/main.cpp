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
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// WAの原因:
// 見ない色でもm色に到達してたらremainに送る処理を入れるべきだった
// 二段階目をソートするのに手間取った
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, m;
    cin >> n >> k >> m;
    vector<pair<ll, int>> vc(n);
    rep(i, n) {
        int c; ll v;
        cin >> c >> v;
        c--;
        vc[i] = {v, c};
    }
    sort(vc.rbegin(), vc.rend());

    // 価値の大きい順に足していく
    vector<pair<ll, int>> remain;
    set<int> colors;
    ll ans = 0;
    rep(i, n) {
        auto [val, color] = vc[i];
        if (!colors.count(color)) {
            if (k && (int)colors.size() < m) {
                ans += val;
                colors.insert(color);
                k--;
            } else {
                remain.push_back({val, color});
            }
            continue;
        }
        remain.push_back({val, color});
    }

    for (auto [val, color] : remain) {
        if (!k) break;
        ans += val;
        k--;
    }
    cout << ans << "\n";
    return 0;
}
