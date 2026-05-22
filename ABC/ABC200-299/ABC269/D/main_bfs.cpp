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

    int N;
    cin >> N;
    vector<pair<int, int>> xy(N);
    set<pair<int, int>> st;
    rep(i, N) {
        cin >> xy[i].first >> xy[i].second;
        st.insert({xy[i].first, xy[i].second});
    }
    
    const int dx[6] = {-1, -1, 0, 0, 1, 1};
    const int dy[6] = {-1, 0, -1, 1, 0, 1};
    int ans = 0;
    while (!st.empty()) {
        queue<pair<int, int>> q;
        q.push(*st.begin());
        st.erase(*st.begin());
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 6; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (st.find({nx, ny}) == st.end()) continue;
                q.push({nx, ny});
                st.erase({nx, ny});
            }
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
