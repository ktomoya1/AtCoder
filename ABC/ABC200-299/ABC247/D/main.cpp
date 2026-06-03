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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    queue<pair<ll, ll>> q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x, c;
            cin >> x >> c;
            q.push({x, c});
        } else {
            ll c;
            cin >> c;
            ll ans = 0;
            while (!q.empty() && c) {
                auto& [val, count] = q.front();
                // countを消費し切る場合
                if (c >= count) {
                    ans += val * count;
                    c -= count;
                    q.pop();
                } else {
                    // countを消費し切らない場合
                    ans += val * c;
                    count -= c;
                    c = 0;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
