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

    int n;
    cin >> n;

    // タグ：逆置換
    // a[i]: i番目にある数字
    // pos[v]: 数字vが今どこにあるか
    vector<int> a(n);
    vector<int> pos(n);
    rep(i, n) {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    vector<pair<int, int>> ans;
    rep(i, n - 1) {
        if (a[i] == i) continue;
        int j = pos[i];
        swap(pos[a[i]], pos[a[j]]);
        swap(a[i], a[j]);
        ans.emplace_back(i, j);
    }
    cout << ans.size() << "\n";
    for (auto [id1, id2] : ans) {
        cout << id1 + 1 << ' ' << id2 + 1 << "\n";
    }
    return 0;
}
