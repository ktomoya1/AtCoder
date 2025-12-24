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
    vector A(7, 0);
    rep(i, 7) {
        if (S[i] == 'a')
            A[i] = 0;
        else if (S[i] == 't')
            A[i] = 1;
        else if (S[i] == 'c')
            A[i] = 2;
        else if (S[i] == 'o')
            A[i] = 3;
        else if (S[i] == 'd')
            A[i] = 4;
        else if (S[i] == 'e')
            A[i] = 5;
        else
            A[i] = 6;
    }
    int ans = 0;
    rep(i, 7) {
        for (int j = i + 1; j < 7; j++) {
            if (A[i] > A[j])
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
