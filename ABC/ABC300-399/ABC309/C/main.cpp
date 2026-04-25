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

    // 今回、種類の情報はいらない
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> p;
    ll sum = 0;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
        sum += b;
    }
    sort(p.begin(), p.end());

    if (sum <= k) {
        cout << 1 << "\n";
        return 0;
    }

    ll days = 1;
    rep(i, n) {
        auto [d, count] = p[i];
        if (sum - count <= k) {
            days = d + 1;
            break;
        }
        sum -= count;
    }
    cout << days << "\n";
    return 0;
}
