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

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<int> score(n);
    for (int j = 0; j < m; j++) {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '0') x++;
            else y++;
        }
        for (int i = 0; i < n; i++) {
            if (!x && !y) {
                score[i]++;
                continue;
            }
            if (s[i][j] == '0') {
                if (x < y) score[i]++;
            } else {
                if (x > y) score[i]++;
            }
        }
    }
    int high = *max_element(score.begin(), score.end());
    bool spc = false;
    for (int i = 0; i < n; i++) {
        if (score[i] == high) {
            if (spc) cout << ' ';
            cout << i + 1;
            spc = true;
        }
    }
    cout << "\n";
    return 0;
}
