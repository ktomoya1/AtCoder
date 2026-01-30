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

    int N, M;
    cin >> N >> M;
    // i番目の研究者が持つ利害関係のない研究者の数
    vector<ll> count(N, N - 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        count[a]--;
        count[b]--;
    }
    rep(i, N) {
        if (i >= 1)
            cout << ' ';
        ll ans = count[i] * (count[i] - 1) * (count[i] - 2) / 6;
        cout << ans;
    }
    cout << "\n";
    return 0;
}
