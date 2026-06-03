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

    // 白いマスは隣接してる黒いマスが存在したら黒にする->元から黒マスは白に変える*10^100回
    // 各マスで何回塗り替えられるか知れたら
    // ある程度波及したら、それ以降は同じ２面を繰り返す
    // vector<vector<string>>でキューのように弾く、３個目が１個目と同じだったら一旦ループ終了
    // あとは残り回数を計算して、
    // 問題はその波及をどう作るかだ
    int h, w;
    cin >> h >> w;

    const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    // まず一面作る：元から黒は白にする、８面見て、黒があったら黒に変える
    for (int i = 0; i < )
    return 0;
}
