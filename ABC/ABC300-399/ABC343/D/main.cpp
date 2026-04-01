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

    // 得点の種類を保持するset
    // その数字が今何個あるのかを数えるmap
    int n, t;
    cin >> n >> t;
    vector<ll> scores(n);
    map<ll, int> cnt;
    cnt[0] = n;
    rep(i, t) {
        int a; ll b;
        cin >> a >> b;
        a--;
        ll cur_score = scores[a];
        // cntに追加が先？scoresに追加が先？
        cnt[cur_score]--;
        if (cnt[cur_score] == 0) {
            cnt.erase(cur_score);
        }
        // scoresに追加
        scores[a] += b;
        cnt[scores[a]]++;
        cout << cnt.size() << "\n";
    }
    return 0;
}
