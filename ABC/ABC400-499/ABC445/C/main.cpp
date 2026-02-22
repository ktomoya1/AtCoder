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

vector<int> a;
vector<int> memo;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N: マスの個数
    // i: マスの番号
    // Ai: マスiに書かれた数字、この数字に移動させる
    // AC: まぐれに近い、制約の見落とし、知識不足
    int n;
    cin >> n;
    // DAG
    vector<int> A(n);
    for (auto &&a : A) {
        cin >> a;
        --a;
    }
//    vector<int> ans(n);
//    for (int i = n - 1; i >= 0; --i) {
//        if (i == A[i]) ans[i] = i;
//        else ans[i] = ans[A[i]];
//    }
//    rep(i, n) {
//        if (i > 0) cout << ' ';
//        cout << ans[i] + 1;
//    }
//    cout << "\n";

    // ダブリング
//    for (int i = 0; i < 100; ++i) {
//        vector<int> tmp(n);
//        for (int j = 0; j < n; ++j) {
//            tmp[j] = A[A[A[A[A[A[A[A[A[A[j]]]]]]]]]];
//        }
//        A = std::move(tmp);
//    }
//    rep(i, n) {
//        if (i > 0) cout << ' ';
//        cout << A[i] + 1;
//    }
//    cout << "\n";
    // path-halving
    for (int i = 0; i < n; ++i) {
        int ans = i;
        while (ans != A[ans]) {
            A[ans] = A[A[ans]];
            ans = A[ans];
        }
        cout << ans + 1 << ' ';
    }
    cout << "\n";
    return 0;
}
