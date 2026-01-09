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

    string S;
    cin >> S;

    // スタックの問題。
    // ACだが、テストケースが運良く通った。
    stack<char> st;
    map<char, char> pairs = {
        {'(', ')'}, {'[', ']'}, {'<', '>'}
    };

    for (auto c : S) {
        // mapにキーが存在する = 開きかっこである
        if (pairs.count(c))
            st.push(c);
        else {
            // )]>が最初に来た時点で空文字列にはならないためNo
            // mapを使ったスマートな書き方
            if (st.empty() || pairs[st.top()] != c) {
                cout << "No\n";
                return 0;
            }
            st.pop();
        }
    }
    if (st.empty()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
