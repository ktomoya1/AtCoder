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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    bitset<10110> dp;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dp = (dp << a) | (dp << b);
    }
    cout << (dp[x] == true ? "Yes" : "No") << "\n";
    return 0;
}
