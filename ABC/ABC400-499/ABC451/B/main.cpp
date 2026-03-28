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

    int n, m;
    cin >> n >> m;
    vector<int> cnt_cur(m, 0), cnt_af(m, 0);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cnt_cur[a]++;
        cnt_af[b]++;
    }
    rep(i, m) cout << cnt_af[i] - cnt_cur[i] << "\n";
    return 0;
}
