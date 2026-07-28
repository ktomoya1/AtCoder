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
// x=4のケースしか試さなかったため、xの値を変更した時、窓がスライドすることに気づかなかった
// そのため、周期性に気づかなかった
// +同じ周期のコストを累積しておく発想にならなかった
// +窓をスライドさせて差分をコストの累積計算する発想がなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        int w2 = w * 2;

        vector<ll> d(w2);
        // iとi+2wはmod2Wでみると同じ値になる
        rep(i, n) d[i % w2] += c[i];

        rep(i, w2) d.push_back(d[i]);

        ll sum = 0;
        rep(i, w) sum += d[i];
        ll ans = sum;
        rep(i, w2) {
            sum -= d[i];
            sum += d[i + w];
            ans = min(ans, sum);
        }
        cout << ans << "\n";
    }
    return 0;
}
