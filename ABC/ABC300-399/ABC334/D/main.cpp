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

    // Ri: i番目のソリを引くのに必要なトナカイの数
    // R配列をソート->累積和をとって、二分探索
    // 方針はわかってたのに、昇順に二分探索するのではなく、降順に二分探索していたため、苦戦
    // upper_boundとlower_boundの使い分けに注意
    // lower_bound: x"以上"の最初の要素を指す
    // upper_bound: x"より大きい"最初の要素を指す
    int n, q;
    cin >> n >> q;
    vector<int> r(n);
    rep(i, n) cin >> r[i];
    sort(r.begin(), r.end());
    vector<ll> s(n + 1);
    rep(i, n) s[i + 1] += s[i] + r[i];
    while (q--) {
        ll x;
        cin >> x;
        auto it = upper_bound(s.begin(), s.end(), x);
        cout << distance(s.begin() + 1, it) << "\n";
    }
    return 0;
}
