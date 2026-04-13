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

    // 累積和の問題
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    rep(i, n - 1) {
        if (s[i] == s[i + 1])
            a[i + 1] = 1;
    }
    rep(i, n - 1) a[i + 1] += a[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << a[r] - a[l] << "\n";
    }
    return 0;
}
