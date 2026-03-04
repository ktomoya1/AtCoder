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

    // 貪欲法でaとbの両方で大きい方から入れていく
    // 箱を購入した後、再度aがbより大きかったら-1を返す
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int ans = -1;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (ans != -1) {
                cout << "-1\n";
                return 0;
            }
            ans = a[i];
            i++;
        }
    }
    if (i < n) {
        if (ans != -1) {
            cout << "-1\n";
            return 0;
        }
        ans = a[i];
    }
    cout << ans << "\n";
    return 0;
}
