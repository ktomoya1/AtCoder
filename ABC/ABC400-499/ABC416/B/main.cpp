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

// 解説AC：#で区切られた各セグメントの先頭にoを置くという規則に気づかなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') cout << '#';
        else if (i == 0 || s[i - 1] == '#') cout << 'o';
        else cout << '.';
    }
    cout << "\n";
    return 0;
}
