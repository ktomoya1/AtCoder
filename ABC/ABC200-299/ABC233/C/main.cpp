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
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// 解けなかった理由:ΠLi<=10^5から、全探索が可能であることを見抜けなかった
// 個数の総積が10^5を超えない->各袋からひとつ選ぶ組み合わせの総数はL1*L2*...*Ln = ΠLi<=10^5
// 分類：パターン認識
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ΠLi <= 10^5から、全探索が可能だと言うことがわかった->dfs
    int n; ll x;
    cin >> n >> x;
    vector<vector<ll>> a(n);
    rep(i, n) {
        int l;
        cin >> l;
        rep(j, l) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    int ans = 0;
    auto dfs = [&](auto self, ll div, int i) -> void {
        // i == n - 1のときはまだ掛ける前だから全てかけ終わった後のi == nで戻る
        if (i == n) {
            if (div == 1) ans++;
            return;
        }
        for (auto d : a[i]) {
            if (div % d == 0) {
                self(self, div / d, i + 1);
            }
        }
    };

    dfs(dfs, x, 0);
    cout << ans << "\n";
    return 0;
}
