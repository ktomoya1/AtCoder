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

    string S;
    cin >> S;

    int n = S.size();
    double ans = 0.0;
    vector<int> cnt(n + 1, 0);
    rep(i, n) {
        cnt[i + 1] = cnt[i] + (S[i] == 't' ? 1 : 0);
    }
    rep(start, n) {
        if (S[start] != 't') continue;
        for (int end = start + 1; end < n; end++) {
            if (S[end] != 't') continue;

            int t_len = end - start + 1;
            if (t_len < 3) continue;

            int x = cnt[end + 1] - cnt[start];

            double t_rate = (x - 2.0) / (t_len - 2.0);
             ans = max(ans, t_rate);
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}
