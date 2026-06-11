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

// ACだけど時間かかった
// 詰まった理由：(i,j)をA+k, B+kの形に対応させる変換に気づくまでに時間がかかった
// 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // P<=i<=QとR<=j<=Sの二重ループで文字を出力するのは確定
    // 問題は(i,j)が黒になる条件が複雑なこと
    // max(1-A,1-B)<=k<=min(N-A,N-B)を満たす全ての整数kについて(A+k,B+k)を黒く塗る
    // この時、i=A+k, j=B+kつまり、k=i-Aかつk=j-Bが同じ値かつ、max(1-A,1-B)<=k<=min(N-A,N-B)の範囲内か調べる
    // 同様に、i=A+k, j=B-k -> k=i-Aかつk=B-jが同じ値かつ、max(1-A,B-N)<=k<=min(N-A,B-1)の範囲内か調べる
    // Adv: k=i-Aかつk=j-Bをさらに式変形するとi-A=j-B->i-j=A-Bと表せる
    // 同様にk=i-Aかつk=B-j -> i-A=B-j -> i+j=A+B
    // こう書けばkすら要らなくなる

    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;

    for (ll i = p; i <= q; i++) {
        for (ll j = r; j <= s; j++) {
            if (i - j == a - b) cout << '#';
            else if (i + j == a + b) cout << '#';
            else cout << '.';
        }
        cout << "\n";
    }
    return 0;
}
