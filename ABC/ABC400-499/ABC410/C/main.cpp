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

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) A[i] = i + 1;
    ll offset = 0;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            // p番目をxに変更する
            A[(offset + p) % N] = x;

        } else if (type == 2) {
            int p;
            cin >> p;
            p--;
            // p番目を出力する
            cout << A[(offset + p) % N] << "\n";

        } else {
            int k;
            cin >> k;
            // k回ローテートする
            // ただし、k <= 10^9よりwhileで回したらTLE
            offset = (offset + k) % N;
        }
    }
    return 0;
}
