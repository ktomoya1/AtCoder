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

    // ## スタック、topより下をアクセスする方法
    string s;
    cin >> s;
    string st;

    for (char c : s) {
        st.push_back(c);
        int n = st.size();
        if (n >= 3 && st[n - 3] == 'A' && st[n - 2] == 'B' && st[n - 1] == 'C') {
            st.erase(st.end() - 3, st.end());
        }
    }
    cout << st << "\n";
    return 0;
}
