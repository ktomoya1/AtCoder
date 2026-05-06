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

    string S;
    cin >> S;
    int n = S.size();
    int a = 0;
    rep(i, n) {
        if (S[i] == '.') continue;
        if (first) {
            cout << i + 1 << ",";
            first = false;
        } else {
            cout << i + 1 << "\n";
            first = true;
        }
    }
    return 0;
}
