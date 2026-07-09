#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// WAの原因：パターン未認識、reverseの状態でaの先頭・末尾にプッシュすることに気づかなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    deque<int> a;

    bool rev = false;
    rep(i, n) {
        if (rev) a.push_front(i + 1);
        else a.push_back(i + 1);
        if (s[i] == 'o') rev = !rev;
    }
    if (rev) reverse(a.begin(), a.end());
    rep(i, n) cout << a[i] << " \n"[i==n-1];
    return 0;
}
