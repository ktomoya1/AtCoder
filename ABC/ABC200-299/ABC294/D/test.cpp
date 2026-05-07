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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    set<int> s;
    vector<bool> visited(n + 1, false);
    int id = 1;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            // 呼ばれてない番号のうち、最小値を選ぶ
            s.insert(id);
            ++id;
        } else if (t == 2) {
            int x;
            cin >> x;
            if (visited[x]) continue;
            s.erase(x);
            visited[x] = true;
        } else {
            int m = 0;
            if (s.size()) m = *s.begin();
            cout << m << "\n";
            s.erase(m);
            visited[m] = true;
        }
    }
    return 0;
}
