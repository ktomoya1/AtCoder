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

// WAの原因；インタラクティブ問題について理解してなかった＋iをインクリメントせずjまで飛ばしたこと
// 出力する時は\nではなく、endlで改行する
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int i = 1, j = i + 1;
    int cnt = 0;
    while (i < n) {
        if (j <= i) j = i + 1;
        while (j <= n) {
            cout << "? " << i << " " << j << endl;
            string res;
            cin >> res;
            if (res == "No") break;
            j++;
        }
        // jはNoの時と範囲外に飛び出した時だから-1
        cnt += j - 1 - i;
        i++;
    }
    cout << "! " << cnt << endl;
    return 0;
}
