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

    // N：人数, T：時点の総数
    // i: 秒数
    // Ai: 選手の番号、Bi：得点増加数
    // i = 1,2, ..., Tそれぞれについて、今からi + 0.5秒後の選手たちの得点は何種類の値があるか表示する
    // O(T)は確実で、O(NT)になる可能性がある
    // どういうデータ型を使うかが問題になってくる
    int N, T;
    cin >> N >> T;
    // どの選手が何点取ってるかを格納する配列
    vector<ll> score(N);
    // どの点数に何人いるかを格納する配列
    map<ll, int> mp;
    // 最初は全員0点
    mp[0] = N;
    while (T--) {
        int a, b;
        cin >> a >> b;
        // 番号を0-index-baseにする
        --a;
        // a番の選手の得点が唯一だった時、mapから消去
        if (--mp[score[a]] == 0) mp.erase(score[a]);
        score[a] += b; // 選手aのスコアを増加
        ++mp[score[a]]; // 新しい得点を記録する
        cout << mp.size() << "\n";
    }
    return 0;
}
