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

    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    rep(i, m) cin >> c[i];
    int ans = 0;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        a--;
        if (c[a] >= b) {
            c[a] -= b;
            ans += b;
        } else {
            if (c[a] != 0) {
                ans += c[a];
                c[a] = 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
