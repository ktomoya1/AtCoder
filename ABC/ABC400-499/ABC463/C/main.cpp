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

// 自力AC
// 時間がかかった原因:secondの二分探索を行う方法を知らなかった,
// 時間が早いかつ身長が低いという条件で除外することができなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<int, int>> p;
    rep(i, n) {
        int h, l;
        cin >> h >> l;
        while (!p.empty() && p.back().first <= h) {
            p.pop_back();
        }
        p.emplace_back(h, l);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        cout << ranges::upper_bound(p, t, {}, &pair<int, int>::second)->first << "\n";
    }
    return 0;
}
