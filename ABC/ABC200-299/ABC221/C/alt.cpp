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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    int ans = 0;
    do {
        for (int i = 1; i < (int)s.size(); i++) {
            string sa, sb;
            for (int j = 0; j < i; j++) sa.push_back(s[j]);
            for(int j = i; j < (int)s.size(); j++) sb.push_back(s[j]);
            ans = max(ans, stoi(sa) * stoi(sb));
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << "\n";
}
