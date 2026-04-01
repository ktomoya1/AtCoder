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

    // タグ：数え上げ、全体から引く
    // 何種類あるか-> 全体の数 - 条件を満たさない組の数
    string s;
    cin >> s;

    ll n = s.size();
    vector<ll> c(26, 0);
    rep(i, n) c[s[i] - 'a']++;
    ll ans = n * (n - 1);
    bool same = false;
    rep(i, 26) {
        if (c[i] > 1) same = true;
        ans -= c[i] * (c[i] - 1);
    }
    ans /= 2;
    if (same) ans++;
    cout << ans << "\n";
    return 0;
}
