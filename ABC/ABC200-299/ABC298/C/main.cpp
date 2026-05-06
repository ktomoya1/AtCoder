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

    // [数][箱] = カウント, [箱][数] = カウントを用意する
    // 間違えた原因：初期化ミス、メモリ制限超過
    // box[y][x]にはxの数字が入るのだから、2e5まで拡張しないと入らない。
    // 範囲外にアクセスしてSEGV
    int n, q;
    cin >> n >> q;
    vector<vector<int>> box(n);
    vector<set<int>> num(2e5);
    while (q--) {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1) {
            int y;
            cin >> y;
            --y;
            // 数xを箱yに入れる
            box[y].push_back(x);
            num[x].insert(y);
        } else if (t == 2) {
            // 箱xに入ってる数を昇順で答える
            sort(box[x].begin(), box[x].end());
            int size = box[x].size();
            rep(i, size) {
                cout << box[x][i] + 1 << " \n"[i == size - 1];
            }
        } else {
            // 数xが入っている箱の番号を昇順で答える
            // setはすでに昇順に管理されているのでそのまま出力できる
            bool first = true;
            for (int v : num[x]) {
                if (!first) cout << ' ';
                cout << v + 1;
                first = false;
            }
            cout << "\n";
        } 
    }
    return 0;
}
