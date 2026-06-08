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

// 斧iの真の持ち主->木こりB[i]
// 木こりB[i]の主張->「自分の斧はA[B[i]]」
// この問題はAがBの逆順列であるかという問題
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    rep(i, n) cin >> a[i + 1];
    rep(i, n) cin >> b[i + 1];

    bool ok = true;
    rep(i, n) {
        if (i != b[a[i]]) ok = false;
    }
    cout << (ok == true ? "Yes" : "No") << "\n";
    return 0;
}
