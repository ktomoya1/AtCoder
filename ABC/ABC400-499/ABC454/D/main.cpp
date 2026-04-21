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

string canonical_form(string s) {
    string t = "";
    for (char c : s) {
        t.push_back(c);
        int n = t.size();
        if (n >= 4 && t[n - 4] == '(' && t[n - 3] == 'x' && t[n - 2] == 'x' && t[n - 1] == ')') {
            t.resize(n - 4);
            t += "xx";
        }
    }
    return t;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ## スタック, 標準形(canonical form)
    // 間違えた原因："(xx)"を"xx"に変更しなかったこと
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "Yes\n";
            continue;
        }
        if (canonical_form(a) == canonical_form(b)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
