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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    ll ans = 0;
    while (true) {
        bool has_kaibun = false;
        for (int i = 0; i <= n - k; ++i) {
            bool is_kaibun = true;
            for (int j = 0; j < k / 2; ++j) {
                if (s[i + j] != s[i + k - j - 1]) {
                    is_kaibun = false;
                    break;
                }
            }
            if (is_kaibun) {
                has_kaibun = true;
                break;
            }
        }
        if (!has_kaibun) ++ans;
        if (!next_permutation(s.begin(), s.end()))
            break;
    }
    cout << ans << "\n";
    return 0;
}
