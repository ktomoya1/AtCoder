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

// 5分で解けなかった理由：整数を文字列に変換するのに苦労した
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> a(10);
    cin >> a[0] >> a[1];

    for (int i = 2; i < 10; i++) {
        string s = to_string(a[i - 2] + a[i - 1]);
        reverse(s.begin(), s.end());
        a[i] = stoll(s);
    }
    cout << a[9] << endl;
    return 0;
}
