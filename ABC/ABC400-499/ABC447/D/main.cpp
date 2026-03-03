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

    // 予想：実際に左に詰める処理を入れるとタイムオーバーする
    // ABCのそれぞれの座標をとって、何組作れるか調べていく
    // ABCの座標はそれぞれ単調増加で、後で戻らないから尺取り法が使えそう
    string s;
    cin >> s;

    int a = 0, b = 0, c = 0;
    for (char t : s) {
        if (t == 'A') a++;
        else if (t == 'B') b = min(a, b + 1);
        else c = min(b, c + 1);
    }
    cout << c << "\n";
    return 0;
}
