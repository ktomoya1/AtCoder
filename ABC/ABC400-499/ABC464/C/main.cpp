#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
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

// 時間がかかった原因：必要なデータ型を考えるまでに時間がかかった
// 出力に必要なものから逆算してみる
// 出力を決める→「j日目の色の種類数」
// それを求めるには何が必要か->各色に何羽いるか
// その情報はどこから来るか->鳥の色変化のイベント
// 入力の何を加工すれば作れるか->days[d]に「その日に色が変わる鳥の番号を入れる」
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 各色に鳥が何羽いるかを保持するデータ型＋色の種類を保持するkind
    // あと日にちごとにどの番号の鳥が変化するか保持するデータ型
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<vector<int>> days(m + 1);
    vector<int> colors(n);
    int kind = 0;
    rep(i, n) {
        int d;
        cin >> a[i] >> d >> b[i];
        a[i]--; b[i]--;
        days[d].push_back(i);
        if (colors[a[i]] == 0) kind++;
        colors[a[i]]++;
    }
    for (int d = 1; d <= m; d++) {
        for (auto i : days[d]) {
            colors[a[i]]--;
            if (colors[a[i]] == 0) kind--;
            colors[b[i]]++;
            if (colors[b[i]] == 1) kind++;
        }
        cout << kind << "\n";
    }
    return 0;
}
