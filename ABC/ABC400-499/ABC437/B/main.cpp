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

    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> A(H, vector(W, 0));
    vector<vector<int>> Count(H, vector(100, 0));
    rep(i, H) {
        rep(j, W) {
            cin >> A[i][j];
            Count[i][A[i][j]]++;
        }
    }
    vector<int> B(N);
    rep(i, N) cin >> B[i];

    int ans = 0;
    rep(i, H) {
        int count = 0;
        rep(j, N) {
            if (Count[i][B[j]] > 0)
                count++;
        }
        ans = max(ans, count);
    }
    cout << ans << "\n";
    return 0;
}
