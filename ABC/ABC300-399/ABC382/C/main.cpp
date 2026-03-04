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
#include <ranges>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    // K: 寿司の美味しさの最大値
    // Bi: 寿司の美味しさ
    // r: まだ誰も食べる人が決まっていないすしのライン。
    const int K = 200010;
    vector<int> id(K, -1);
    int r = K;
    rep(i, n) {
        int a;
        cin >> a;
        while (r > a) {
            --r;
            id[r] = i + 1;
        }
    }
    rep(j, m) {
        int b;
        cin >> b;
        cout << id[b] << "\n";
    }
    return 0;
}
