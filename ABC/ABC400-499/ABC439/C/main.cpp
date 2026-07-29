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
// 解けなかった原因：計算量の見誤り->x、yのループはそれぞれO(√N)なので二重ループはO(N)になる。
// そのため、全探索可能。
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int x = 1; x * x <= n; x++) {
        for (int y = x + 1; x * x + y * y <= n; y++) {
            c[x * x + y * y]++;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) ans.push_back(i);
    }
    int an = ans.size();
    cout << an << "\n";
    rep(i, an) cout << ans[i] << " \n"[i == an - 1];
    return 0;
}
