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

    // タグ：文字列の一括置換、遅延評価
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> convert(26);
    iota(convert.begin(), convert.end(), 0);
    while (q--) {
        char c_chr, d_chr;
        cin >> c_chr >> d_chr;
        int c = c_chr - 'a';
        int d = d_chr - 'a';
        if (c == d) continue;
        rep(i, 26) {
            if (convert[i] == c) convert[i] = d;
        }
    }
    for (char c : s) {
        cout << (char)('a' + convert[c - 'a']);
    }
    cout << "\n";
    return 0;
}
