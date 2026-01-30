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

    string S;
    cin >> S;

    int ans = 0;
    for (char c : S) {
        if (c == 'i' || c == 'j')
            ans++;
    }
    cout << ans << "\n";
    return 0;
}
