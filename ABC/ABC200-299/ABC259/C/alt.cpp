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

    string S, T;
    cin >> S >> T;

    // ランレングス圧縮はポインタ操作でも実現できる
    int i = 0, j = 0;
    int n = S.size(), m = T.size();
    while (i < n && j < m) {
        char ch_s = S[i];
        int cnt_s = 0;
        while (i < n && S[i] == ch_s) {
            cnt_s++;
            i++;
        }
        char ch_t = T[j];
        int cnt_t = 0;
        while (j < m && T[j] == ch_t) {
            cnt_t++;
            j++;
        }
        if (ch_s != ch_t || cnt_s > cnt_t || (cnt_s == 1 && cnt_t > 1)) {
            cout << "No\n";
            return 0;
        }
    }
    if (i == n && j == m) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
