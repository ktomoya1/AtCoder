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

const int INF = 2e9;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    string S;
    cin >> S;

    // Sの文字の数だけXi, Yiを動かすO(N)
    // 各Xi, Yiどうしを比較して衝突が発生するか確認するのはO(N^2)で不可能
    // なので、座標全てを記録し、カウントしようと考えるが、
    // Xi, Yiの制約から座標全てをvectorに保存することは不可能
    // なので、mapを使う
    // 全ての人が歩き続けた時という文言を見逃していた
    // map<pair<int, int>, int> mp;
    // rep(i, N) {
    //     int x = X[i], y = Y[i];
    //     if (S[i] == 'R')
    //         x++;
    //     else x--;
    //     mp[{x, y}]++;
    //     if (mp[{x, y}] > 2) {
    //         cout << "Yes" << "\n";
    //         return 0;
    //     }
    // }
    // cout << "No" << "\n";

    // map<Y座標、pair<minR, max_L>>
    map<int, pair<int, int>> mp;

    rep(i, N) {
        int y = Y[i];
        int x = X[i];

        // そのY座標がmapにまだなければ、初期値{INF, -1}で作成
        if (mp.find(y) == mp.end()) {
            mp[y] = {INF, -1};
        }

        if (S[i] == 'R') {
            // 右向きなら、一番左側にいる人の座標を更新したい
            mp[y].first = min(mp[y].first, x);
        } else {
            mp[y].second = max(mp[y].second, x);
        }
    }

    for (auto p : mp) {
        // p.secondはpair<min_R, max_L>
        int min_r = p.second.first;
        int max_l = p.second.second;

        // RがLより左にいたら衝突する(R -> <~ Lの形)
        // ? なんでRがLより左にいたら衝突するの?
        if (min_r < max_l) {
            cout << "Yes" << "\n";
            return 0;
        }
    }
    cout << "No" << "\n";
    return 0;
}
