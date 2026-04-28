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

    // ## 頻度分布、map、ソート
    // reverse_map[value] = keyのように、mapのvalueをkeyに移動させようとすると、
    // 元のmapの値と衝突する可能性がある。おそらくそれでWAになった
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    // 頻度分布を使いたいけど、制約で厳しい->map型
    map<ll, ll> mp;
    rep(i, n) mp[a[i]] += a[i];
    ll ans = 0;
    vector<ll> values;
    for (auto [key, value] : mp) {
        ans += value;
        values.push_back(value);
    }
    int cnt = 0;
    sort(values.rbegin(), values.rend());
    for (int i = 0; i < (int)values.size(); i++) {
        ans -= values[i];
        cnt++;
        if (cnt == k) break;
    }
    cout << ans << "\n";
    return 0;
}
