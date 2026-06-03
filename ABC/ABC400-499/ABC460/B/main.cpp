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

// 40分かかった原因：double型dをsqrtで　求めるとダメ。
// double型が表現できるのは整数15-16桁
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll xd = abs(x1 - x2), yd = abs(y1 - y2);
        ll sqrx = xd * xd, sqry = yd * yd;
        ll d = sqrx + sqry;
        if (d >= (r1 - r2) * (r1 - r2) && d <= (r1 + r2) * (r1 + r2)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
