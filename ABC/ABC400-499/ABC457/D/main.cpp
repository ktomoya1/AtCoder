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

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// 解けなかった原因：解の二分探索について知らなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // minAiをxとすると、
    // a[i] + k*i >= x -> k >= (x - a[i]) / i（切り上げ）になる
    auto isok = [&](ll x) -> bool {
        ll nk = 0;
        // ゼロ除算を防ぐため、1-indexedに変更
        for (int i = 1; i <= n; i++) {
            if (a[i] < x) {
                nk += (x - a[i] + i - 1) / i; // 切り上げ
                if (nk > k) { return false; }
            }
        }
        return true;
    };

    ll ok = 1;
    ll ng = a[1] + k + 1; // a[1]にK回全て操作しても届かない値

    // 二分探索
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (isok(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << "\n";
    return 0;
}
