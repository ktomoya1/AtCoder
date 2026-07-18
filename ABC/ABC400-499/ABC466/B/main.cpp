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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 色Ci、大きさSi
    int n, m;
    cin >> n >> m;
    vector<int> size(m, -1);
    rep(i, n) {
        int c, s;
        cin >> c >> s;
        c--;
        size[c] = max(size[c], s);
    }
    rep(i, m) {
        if (i) cout << ' ';
        cout << size[i];
    }
    cout << '\n';
    return 0;
}
