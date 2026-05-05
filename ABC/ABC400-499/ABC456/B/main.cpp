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

    vector<vector<int>> a(3, vector<int>(6));
    rep(i, 3) {
        rep(j, 6) cin >> a[i][j];
    }

    double ans = 0;
    rep(i, 6) {
        rep(j, 6) {
            rep(k, 6) {
                vector<int> v = {a[0][i], a[1][j], a[2][k]};
                sort(v.begin(), v.end());
                if (v == vector<int>{4, 5, 6})
                    ans++;
            }
        }
    }
    cout << fixed << setprecision(15) << ans / 216 << "\n";
    return 0;
}
