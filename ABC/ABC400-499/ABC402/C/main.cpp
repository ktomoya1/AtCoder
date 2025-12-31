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

    // 依存関係があーだこーだみたいな問題
    // O(NM)はTLE
    int N, M;
    cin >> N >> M;
    // 逆引きリスト：各食材で使う料理の配列
    vector<vector<int>> idx(N);
    vector<int> cnt(M);
    rep(i, M) {
        int k;
        cin >> k;
        cnt[i] = k;
        while (k--) {
            int a;
            cin >> a;
            a--;
            idx[a].push_back(i);
        }
    }
    int ans = 0;
    while (N--) {
        int b;
        cin >> b;
        b--;
        for (auto i : idx[b]) {
            cnt[i]--;
            if (cnt[i] == 0)
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
