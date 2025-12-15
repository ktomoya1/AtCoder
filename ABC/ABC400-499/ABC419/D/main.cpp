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
    string S, T;
    cin >> S >> T;
    vector<int> imos(N, 0);
    // いもす法
    while (M--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        imos[l]++;
        imos[r + 1]--;
    }
    // 累積和をとる
    rep(i, N) imos[i + 1] += imos[i];
    string ans;
    rep(i, N) {
        if (imos[i] % 2 == 1) {
            ans += T[i];
        } else {
            ans += S[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
