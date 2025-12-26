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

    // 正整数N, Q
    // 長さ2Nの文字列を作り、行ったり来たりする
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    int start = 0;
    while (Q--) {
        int type;
        cin >> type;
        int x;
        cin >> x;
        if (type == 1) {
            // x文字分後ろに移動する
            start = (start + N - x) % N;
        } else {
            cout << S[(start + x - 1) % N] << "\n";
        }
    }
    return 0;
}
