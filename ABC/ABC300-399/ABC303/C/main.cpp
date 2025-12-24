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

    // Sで行動は決められているので、普通に実装でいい
    // Sが長すぎる場合、都度現在地と一番近い回復地点の距離を探していたら、O(NM)になりそう。
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<pair<int, int>> recover;
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        recover.insert({x, y});
    }
    int hp = H;
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        hp--;
        if (S[i] == 'R') x++;
        else if (S[i] == 'L') x--;
        else if (S[i] == 'U') y++;
        else y--;
        if (hp < 0) {
            cout << "No" << "\n";
            return 0;
        } else {
            if (recover.count({x, y}) > 0 && hp < K) {
                recover.erase({x, y});
                hp = K;
            }
        }
    }
    cout << "Yes" << "\n";
    return 0;
}
