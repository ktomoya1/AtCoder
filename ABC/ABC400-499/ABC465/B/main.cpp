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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    ll ans = 0;
    for (int i = a; i < b; i++) {
        if (l <= i && i < r) {
            ans += x;
        } else {
            ans += y;
        }
    }
    cout << ans << "\n";
    return 0;
}
