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
    vector<string> s(n);
    int max_size = 0;
    rep(i, n) {
        cin >> s[i];
        max_size = max(max_size, (int)s[i].size());
    }
    rep(i, n) {
        int count = (max_size - (int)s[i].size()) / 2;
        string t = string(count, '.') + s[i] + string(count, '.');
        cout << t << "\n";
    }
    return 0;
}
