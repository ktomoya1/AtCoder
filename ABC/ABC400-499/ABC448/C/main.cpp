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
    vector<pair<int, int>> a(n);
    rep(i, n) {
        int val;
        cin >> val;
        a[i] = {val, i + 1};
    }

    sort(a.begin(), a.end());

    int m = min(n, 6);
    vector<pair<int, int>> candidates;
    for (int i = 0; i < m; ++i) candidates.push_back(a[i]);

    while (q--) {
        int k;
        cin >> k;
        vector<int> b(k);
        rep(i, k) cin >> b[i];
        for (const auto& [val, id] : candidates) {
            bool is_removed = false;
            for (int removed_id : b) {
                if (id == removed_id) {
                    is_removed = true;
                    break;
                } 
            }
            if (!is_removed) {
                cout << val << "\n";
                break;
            }
        }
    }
    return 0;
}
