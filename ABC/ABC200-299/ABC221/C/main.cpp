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

// 解説AC: 計算量を正確に見積もれなかったので全探索できることに気づかなかった
// +貪欲で解こうとしたが最適性の証明ができなかった
// 9! * 8は十分に計算できる
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    sort(s.rbegin(), s.rend());
    string sa, sb;
    int n = s.size();
    rep(i, n) {
        if (i % 2 == 1) sa.push_back(s[i]);
        else sb.push_back(s[i]);
    }

    for (int i = 0; i < min((int)sa.size(), (int)sb.size()); i++) {
        if (sa[i] != sb[i]) {
            swap(sa[i], sb[i]);
            // 2回以上のswapは逆に差が広がる
            break;
        }
    }
    cout << stoi(sa) * stoi(sb) << '\n';
}
