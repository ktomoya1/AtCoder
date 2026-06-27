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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 列車AはS0に対応
    int n;
    char x;
    cin >> n >> x;

    bool ans = false;
    rep(i, n) {
        string s;
        cin >> s;
        ans |= s[x - 'A'] == 'o';
    }
    cout << (ans == true ? "Yes" : "No") << "\n";
    return 0;
}
