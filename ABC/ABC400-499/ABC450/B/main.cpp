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

    int n;
    cin >> n;

    vector<vector<int>> C(n - 1, vector<int>(n, 0));
    rep(i, n - 1) {
        for (int j = i + 1; j < n; ++j) {
            cin >> C[i][j];
        }
    }

    rep(a, n - 1) {
        for (int b = a + 1; b < n; ++b) {
            for (int c = b + 1; c < n; ++c) {
                if (C[a][b] + C[b][c] < C[a][c]) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
