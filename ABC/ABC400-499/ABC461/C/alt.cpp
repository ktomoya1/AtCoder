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
#include <bitset>

using namespace std;
using ll = long long;

#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)

// 色M種類以上->色を軸に考える
// 制約に出てくる要素を軸に分類を考える
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<ll>> t(n + 1);
    rep(i, n) {
        int c; ll v;
        cin >> c >> v;
        t[c].push_back(v);
    }

    // 各色の一番価値が大きい要素をtopに入れる->topをソートしてm色選ぶ
    // 残りのk - m個はtail（ソート済み）から取り出す
    vector<ll> top, tail;
    for (auto& r : t) {
        if (r.empty()) continue;
        sort(r.rbegin(), r.rend());
        top.push_back(r[0]);
        for (int i = 1; i < (int)r.size(); i++) tail.push_back(r[i]);
    }
    sort(top.rbegin(), top.rend());

    ll ans = 0;
    for (int i = 0; i < m; i++) ans += top[i];
    for (int i = m; i < (int)top.size(); i++) tail.push_back(top[i]);
    sort(tail.rbegin(), tail.rend());

    for (int i = 0; i < k - m; i++) ans += tail[i];
    cout << ans << "\n";
    return 0;
}
