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

    // ## 有向グラフ, 有向閉路
    // なぜ解けなかったのか：
    // - 閉路ができた時に、その前のノードの切り離し方がわからなかった
    // - デバッグに苦労した
    int n;
    cin >> n;
    // 分岐しないのでDFSをする必要がない
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<bool> seen(n);
    int v = 0;
    // 閉路の起点を見つける
    while (!seen[v]) {
        seen[v] = true;
        v = a[v];
    }
    vector<int> ans;
    // 閉路まで一周する
    // スイッチをtrueからfalseに変えるのがミソ
    while (seen[v]) {
        seen[v] = false;
        ans.push_back(v);
        v = a[v];
    }
    int size = ans.size();
    cout << size << "\n";
    rep(i, size) {
        if (i) cout << ' ';
        cout << ans[i] + 1;
    }
    cout << "\n";
    return 0;
}
