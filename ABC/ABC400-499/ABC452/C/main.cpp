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

    // ## 実装、全探索、三次元配列
    // <ミス>脊椎に書く文字列の長さはNであるという文章が抜け落ちてた
    // その他、三次元配列を実装するのに手間取っていた
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    int m;
    cin >> m;
    vector<string> s(m);
    rep(i, m) cin >> s[i];
    // Sの長さ、Sの位置、どのアルファベットが存在するか
    vector<vector<vector<bool>>> has(10, vector<vector<bool>>(10, vector<bool>(26, false)));
    rep(i, m) {
        int s_size = s[i].size();
        rep(j, s_size) {
            has[s_size - 1][j][s[i][j] - 'a'] = true;
        }
    }
    rep(i, m) {
        int s_size = s[i].size();
        if (s_size != n) {
            cout << "No\n";
            continue;
        }
        bool ok = true;
        rep(j, n) {
            if (!has[a[j]][b[j]][s[i][j] - 'a']) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
