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

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    for (int i = 0; i < K; i++) {
        vector<int> b;
        for (int k = i; k < N; k += K) {
            b.push_back(a[k]);
        }
        sort(b.begin(), b.end());
        for (int k = i; k < N; k += K) {
            a[k] = b[k / K];
        }
    }
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i - 1]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
