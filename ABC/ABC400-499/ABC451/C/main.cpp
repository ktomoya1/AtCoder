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

    // 解法1：multiset + upper_bound -> beginからitまで範囲削除
    // 解法2: 優先度つきキュー
    // 解けなかった原因：lower_boundとupper_boundの境界条件があやふや、
    // 木が重複することを見落とした、erase(first, last)の存在を知らなかった
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q--) {
        int t, h;
        cin >> t >> h;
        if (t == 1) {
            pq.push(h);
        } else {
            while (!pq.empty() && pq.top() <= h)
                pq.pop();
        }
        cout << pq.size() << "\n";
    }
    return 0;
}
