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

    // 累積和を使おうにも、先頭の蛇が抜けた時に累積和を計算し直さなきゃいけない
    // vector<pair<ll, ll>>で座標と長さの管理
    int q;
    cin >> q;
    vector<ll> m;
    ll now = 0;
    int id = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll l;
            cin >> l;
            m.push_back(now);
            now += l;
        } else if (t == 2) {
            id++;
        } else {
            int k;
            cin >> k;
            k--;
            cout << m[id + k] - m[id] << "\n";
        }
    }
    return 0;
}
