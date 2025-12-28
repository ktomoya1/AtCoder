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

    // 数字列S, T
    // N: Sの長さN, M: Tの長さ
    // Tを1文字選び、選んだ数字を１増やす。ただし、選んだ数字が9の場合は0にする
    // TをSの部分文字列（連続する部分列）にするために必要な操作回数の最小値を求めよ
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    int ans = 1e9;
    // iはNからMを引いた長さまでしか動けない
    for (int i = 0; i <= N - M; i++) {
        int diff = 0;
        for (int j = 0; j < M; j++) {
            diff += (S[i + j] - T[j] + 10) % 10;
        }
        ans = min(ans, diff);
    }
    cout << ans << "\n";
    return 0;
}
