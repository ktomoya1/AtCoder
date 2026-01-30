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

    int n, q;
    cin >> n >> q;
    vector<int> a(n), s(n + 1, 0);
    rep(i, n) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            --x;
            swap(a[x], a[x + 1]);
            s[x + 1] = s[x] + a[x];
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            cout << s[r] - s[l] << "\n";
        }
    }
    return 0;
}
