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

pair<string, vector<int>> decompose(const string &s) {
    string t = "";
    vector<int> v;
    int count = 0;
    for (char c : s) {
        if (c == 'A')
            ++count;
        else {
            t += c;
            v.push_back(count);
            count = 0;
        }
    }
    v.push_back(count);
    return {t, v};
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 一致条件：SとTのA以外の文字の数が一致すること
    // 上は間違いでAの文字を抜いた時にSとTが一致すること
    string s, t;
    cin >> s >> t;

    auto [ss, sv] = decompose(s);
    auto [ts, tv] = decompose(t);
    if (ss != ts) {
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < (int)sv.size(); ++i)
        ans += abs(sv[i] - tv[i]);
    cout << ans << "\n";
    return 0;
}
