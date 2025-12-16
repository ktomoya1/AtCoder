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

int N, X, K;
vector<string> S;
vector<string> dict;

void make_string(int count, string current_s) {
    if (count == K) {
        dict.push_back(current_s);
        return;
    }
    rep(i, N) {
        make_string(count + 1, current_s + S[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> X;

    S.resize(N);

    rep(i, N) cin >> S[i];

    // DFSを使った多重for文のループ
    make_string(0, "");
    sort(dict.begin(), dict.end());
    cout << dict[X - 1] << "\n";

    return 0;
}
