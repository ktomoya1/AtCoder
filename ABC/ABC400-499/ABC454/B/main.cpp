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

    // N人全員が異なる種類の服を着ていますか？→setのsizeがNならいい
    // M種類の服全てについて、その服を着ている人が少なくとも一人ずついるか？
    // →setは重複不可の服の種類を格納しているため、これもsetのsizeを取ればいい
    int n, m;
    cin >> n >> m;
    set<int> s;
    rep(i, n) {
        int f;
        cin >> f;
        s.insert(f);
    }
    cout << ((int)s.size() == n ? "Yes" : "No") << "\n";
    cout << ((int)s.size() == m ? "Yes" : "No") << "\n";
    return 0;
}
