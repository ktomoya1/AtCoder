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

    string s;
    cin >> s;

    vector<int> count(26, 0);
    int max_count = 0;
    for (char c : s) {
        int id = c - 'a';
        count[id]++;
        max_count = max(max_count, count[id]);
    }
    string t = "";
    for (char c : s) {
        int id = c - 'a';
        if (count[id] != max_count)
            t += c;
    }
    cout << t << "\n";
    return 0;
}
