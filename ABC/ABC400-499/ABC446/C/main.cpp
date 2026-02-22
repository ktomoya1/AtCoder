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

    // D日語の管理が難しい
    // queueを使う
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        queue<int> q; // 残りの卵、締切日数
        rep(i, n) {
            // ai個の卵を仕入れる
            rep(j, a[i]) q.push(i);
            // bi個の卵を消費する
            rep(j, b[i]) q.pop();
            // D日後の卵は処理する
            while (!q.empty() && q.front() == i - d) q.pop();
        }
        cout << q.size() << "\n";
    }
    return 0;
}
