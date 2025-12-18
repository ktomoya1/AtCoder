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

    int Q;
    cin >> Q;

    // cの制約が10^9, k <= 10^9あるので、dequeに何回もプッシュする余裕はない
    // pairを使う発想にならない
    deque<pair<ll, ll>> d;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll c, x;
            cin >> c >> x;
            d.push_back({x, c});
        } else {
            ll k;
            cin >> k;
            ll sum = 0;
            while (k > 0) {
                ll val = d.front().first;
                ll count = d.front().second; 
                if (count <= k) {
                    sum += val * count;
                    k -= count;
                    d.pop_front();
                } else {
                    sum += val * k;
                    d.front().second = count - k;
                    k = 0;
                }
            }
            cout << sum << "\n";
        }

    }
    return 0;
}
