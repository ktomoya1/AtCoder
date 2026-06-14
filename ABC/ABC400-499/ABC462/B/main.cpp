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

    // iが人、Ai,1,Ai,2,Ai,3,...は送り先の人、Kiはiの合計人数(送り先）
    // i=1,2,,...,Nに対し、人iにギフトを送った人
    int n;
    cin >> n;
    vector<set<int>> b(n);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            b[a].insert(i);
        }
    }

    rep(i, n) {
        cout << b[i].size();
        if (b[i].size()) {
            for (auto v : b[i]) {
                cout << ' ';
                cout << v + 1;
            }
        }
        cout << "\n";
    }
    return 0;
}
