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

    // ゴール：条件を満たす整数i, jの組の総数を求める
    // O(N^2) = TLE
    // 問題は、組み合わせをどうやってO(1), O(logN)で求めるのかわからない
    // posとaが同じ数字をカウントし、nCmで計算
    // 残りは、a[a[pos]] == posだったら+1
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    rep(i, N) {
        for (int j = i + 1; j < N; j++) {
            if (min(a[i], a[j]) == i && max(a[i], a[j]) == j) ans++; 
        }
    }
    cout << ans << "\n";
    return 0;
}
