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

#define rep(i, l, r) for (int i = (l); i < (r); i++)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    // 前の文字と現在の文字を比較して違ったら、カウントする
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] + 1 != s[i + 1]) continue;
        int l = i, r = i + 1;
        while (l >= 0 && s[l] == s[i]) --l;
        while (r < n && s[r] == s[i + 1]) ++r;
        ans += min(i - l, r - (i + 1));
    }
    cout << ans << "\n";
    return 0;
}
