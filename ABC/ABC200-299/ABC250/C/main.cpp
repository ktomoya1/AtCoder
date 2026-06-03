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

    // x1, ..., xqをO(1)で取り出せればO(q)で済む
    // 0-2e5+10の座標配列を用意する
    int n, q;
    cin >> n >> q;
    vector<int> pos(n + 1); // 数字が持つ位置
    vector<int> num(n + 1); // 各位置が何の数字を持ってるか
    iota(pos.begin(), pos.end(), 0);
    iota(num.begin(), num.end(), 0);

    while (q--) {
        int x;
        cin >> x;
        int cpos = pos[x];
        // xが置かれてるボールの右隣のボールと入れ替える
        int npos = (cpos < n) ? cpos + 1 : cpos - 1;
        int nnum = num[npos];

        pos[x] = npos;
        pos[nnum] = cpos;
        num[cpos] = nnum;
        num[npos] = x;
    }

    for (int i = 1; i <= n; i++) {
        cout << num[i] << " \n"[i == n];
    }
    return 0;
}
