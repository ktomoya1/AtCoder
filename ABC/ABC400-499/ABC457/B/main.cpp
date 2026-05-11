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

// 落とした原因：制約の見落とし->次から制約から最大メモリを見積もる習慣をつける
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> A(N);
    rep(i, N) {
        int L;
        cin >> L;
        // 長さをここで確保する
        A[i].resize(L);
        rep(j, L) cin >> A[i][j];
    }
    int X, Y;
    cin >> X >> Y;
    --X; --Y;
    cout << A[X][Y] << "\n";
    return 0;
}
