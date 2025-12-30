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

    // ボタンA：文字列tの末尾に0を追加
    // ボタンB：tに含まれる数字0-8は+1, 9は0になる
    // 求めるものはボタンをSと一致するまで押した回数
    // tがj文字目でSjになる回数はSj = (bj + ... + bN) % 10
    string S;
    cin >> S;
    ll sum = 0;
    int N = S.size();
    for (int i = N - 1; i >= 0; i--) {
        int v = S[i] - '0';
        int u = ((i < N - 1) ? S[i + 1] - '0' : 0);
        int b = (10 + v - u) % 10;
        sum += b;
    }
    int ans = sum + N;
    cout << ans << "\n";
    return 0;
}
