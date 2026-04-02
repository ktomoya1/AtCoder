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

    // ## 進数変換、k進法への帰着
    // 5進数に変換する発想が引き出しになかった。
    ll n;
    cin >> n;
    --n;
    vector<int> a;
    while (n) {
        a.push_back(n % 5);
        n /= 5;
    }
    if (a.empty()) a.push_back(0);
    reverse(a.begin(), a.end());
    for (auto& x : a) cout << x * 2;
    cout << "\n";
    return 0;
}
