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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 並べ替えられるから、順番は気にしなくて良い
    // 溶けたけど時間がかかった原因：set<char>を"atcoder"で初期化する方法がわからなかった
    string s, t;
    cin >> s >> t;
    vector<int> cnt_a(27), cnt_b(27);
    rep(i, (int)s.size()) {
        if (s[i] == '@') ++cnt_a[26];
        else ++cnt_a[s[i] - 'a'];
        if (t[i] == '@') ++cnt_b[26];
        else ++cnt_b[t[i] - 'a'];
    }
    // setの代わりにビットフラグを利用できる
    // 検索するときのO(logN)をO(1)に抑えられる
    int mask = 0;
    for (char c : string("atcoder")) mask |= (1 << (c - 'a'));
    rep(i, 26) {
        if (cnt_a[i] == cnt_b[i]) continue;
        if (!((mask >> i) & 1)) {
            cout << "No\n";
            return 0;
        }
        cnt_a[26] -= max(0, cnt_b[i] - cnt_a[i]);
        cnt_b[26] -= max(0, cnt_a[i] - cnt_b[i]);
        if (cnt_a[26] < 0 || cnt_b[26] < 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
