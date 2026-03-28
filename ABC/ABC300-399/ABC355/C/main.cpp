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

    // 何ターン目にビンゴしてるか判定するのが難しいポイント
    int n, t;
    cin >> n >> t;
    vector<int> cnt_row(n, 0);
    vector<int> cnt_col(n, 0);
    vector<int> diag(2, 0);
    for (int i = 1; i <= t; i++) {
        int a;
        cin >> a;
        --a;
        int r = a / n;
        int c = a % n;
        ++cnt_row[r];
        ++cnt_col[c];
        if (r == c) ++diag[0];
        if (r == n - 1 - c) ++diag[1];
        if (cnt_row[r] == n || cnt_col[c] == n
            || diag[0] == n || diag[1] == n) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
