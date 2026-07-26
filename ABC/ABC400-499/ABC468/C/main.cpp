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

// AC
// vector同士で比較できるのを知ってたらもっと早く解けてたかも
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int ans = 0;
    do {
        // vector同士は辞書の大小で比較可能
        if (p < a && a < q) ans++;
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << "\n";
    return 0;
}
