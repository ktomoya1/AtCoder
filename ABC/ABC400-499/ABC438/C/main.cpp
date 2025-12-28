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

    // N: 整数列の長さ
    // A = (A1, A2, ..., AN)
    // 求めるもの：操作を繰り返した後の最終的な|A|の最小値
    int N;
    cin >> N;

    // vectorを用いたstack構造を使う    
    vector<int> stack;
    rep(i, N) {
        int a;
        cin >> a;
        
        stack.push_back(a);
        int size = stack.size();
        if (size >= 4) {
            if (stack[size - 1] == stack[size - 2]
            && stack[size - 2] == stack[size - 3]
            && stack[size - 3] == stack[size - 4]) {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
            }
        }
    }
    cout << stack.size() << "\n";
    return 0;
}
