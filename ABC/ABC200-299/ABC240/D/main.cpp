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
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// 解説AC、間違えた原因：トータル数の管理方法がわからなかった、st.size()で出力しようという
// 固定観念があった, あとスタックとしてのRLEの使い方に慣れてなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total = 0;
    vector<pair<int, int>> st;
    rep(i, n) {
        int a;
        cin >> a;

        if (!st.empty() && st.back().first == a) {
            st.back().second++;
        } else {
            st.push_back({a, 1});
        }
        total++;

        if (st.back().second == st.back().first) {
            total -= st.back().first;
            st.pop_back();
        }
        cout << total << "\n";
    }
    return 0;
}
