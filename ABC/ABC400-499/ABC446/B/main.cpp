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
    vector<bool> isused(m + 1, false);
    rep(i, n) {
        int len;
        cin >> len;

        int ans = 0;
        rep(j, len) {
            int x;
            cin >> x;
            if (ans == 0 && !isused[x]) {
                ans = x;
                isused[x] = true;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
