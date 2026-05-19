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

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 間違えた原因：優先度キューをO(N)と思い込んで選択肢を外した
    // +優先度キューを二つ使う発想にならなかった
    int X, Q;
    cin >> X >> Q;
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;
    L.push(X);

    auto add = [&](int x) -> void {
        if (x <= L.top()) {
            L.push(x);
        } else {
            R.push(x);
        }

        if ((int)L.size() <= (int)R.size()) {
            L.push(R.top());
            R.pop();
        }
        if ((int)L.size() > (int)R.size() + 1){
            R.push(L.top());
            L.pop();
        }
    };

    while (Q--) {
        int a, b;
        cin >> a >> b;
        add(a); add(b);
        cout << L.top() << "\n";
    }
    return 0;
}
