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

void encode(string s, vector<pair<char, int>>& encoder) {
    int cnt = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            encoder.push_back({s[i - 1], cnt});
            cnt = 1;
        }
    }
    encoder.push_back({s.back(), cnt});
}

// 間違えた原因：問題をちゃんと読んでいない、次は操作の方向性を最初に確認する習慣をつける
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 好きな回数の操作後、SとTが一致するか判定する
    string S, T;
    cin >> S >> T;
    // ランレングス圧縮->vector<pair<int, int>>
    vector<pair<char, int>> rle_s;
    vector<pair<char, int>> rle_t;

    encode(S, rle_s);
    encode(T, rle_t);
    // print(rle_s);
    // print(rle_t);

    int es_size = rle_s.size(), et_size = rle_t.size();
    if (es_size != et_size) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < es_size; i++) {
        auto [s_ch, s_cnt] = rle_s[i];
        auto [t_ch, t_cnt] = rle_t[i];
        if (s_ch == t_ch && s_cnt == 1 && t_cnt == 1) continue;
        if (s_ch == t_ch && s_cnt > 1 && t_cnt > 1 && s_cnt <= t_cnt) continue;
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}
