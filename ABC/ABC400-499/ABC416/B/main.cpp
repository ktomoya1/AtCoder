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
    bool seen_sharp = false;
    for (int i = 0; i < n; i++) {
        if (!seen_sharp && s[i] == '.') {
            s[i] = 'o';
            seen_sharp = true;
        } else if (s[i] == '#') {
            seen_sharp = false;
        }
    }
    cout << s << "\n";
    return 0;
}
