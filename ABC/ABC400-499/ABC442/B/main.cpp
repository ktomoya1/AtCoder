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

    int q;
    cin >> q;
    // x: 音量 y: bool型
    int x = 0, y = 0;
    while (q--) {
        int a;
        cin >> a;
        if (a == 1) x++;
        else if (a == 2 && x > 0) x--;
        else if (a == 3) y = 1 - y;
        if (x >= 3 && y == 1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
