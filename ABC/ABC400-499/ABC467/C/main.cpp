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

// 解説AC
// 原因：A1の状態が決まった時に自ずと他の状態が連鎖的に決まることに気づかなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n-1) cin >> b[i];

    auto solve = [&](int first_val) -> int {
        int ans = 0;
        int prev = first_val;
        if (a[0] != first_val) ans++;
        for (int i = 0; i < n - 1; i++) {
            int next = ((b[i] - prev) % m + m) % m;
            if (a[i+1] != next) ans++;
            prev = next;
        }
        return ans;
    };

    int ans1 = solve(a[0]);
    int ans2 = solve(a[0] ^ 1);
    cout << min(ans1, ans2) << "\n";
    return 0;
}
