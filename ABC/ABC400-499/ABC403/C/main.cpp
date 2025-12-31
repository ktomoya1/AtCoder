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

    int N, M, Q;
    cin >> N >> M >> Q;
    // map(ユーザの人数、コンテストページの番号の集合)
    vector<set<int>> view(N);
    vector<bool> all_view(N, false);
    while (Q--) {
        int type;
        cin >> type;
        int x;
        cin >> x;
        x--;
        if (type == 1) {
            int y;
            cin >> y;
            y--;
            view[x].insert(y);
        } else if (type == 2) {
            // 権限を全て付与するのにO(N);
            all_view[x] = true;
        } else {
            int y;
            cin >> y;
            y--;
            if (all_view[x] == true || view[x].count(y))
                cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }
    return 0;
}
