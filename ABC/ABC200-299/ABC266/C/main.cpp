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

// cross(P, Q, R) = PQ × QR
int cross(int px, int py, int qx, int qy, int rx, int ry) {
    return (qx - px) * (ry - qy) - (qy - py) * (rx - qx);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ゴール：四角形が凸かどうか判定したい
    // 凸の定義は「4つの内角が全て180度未満」
    // 内角をどう測るか：頂点Bの内角=辺BA方向から辺BC方向への反時計回りに測った角度。
    // BA方向からBC方向への角度を計算したい
    // BA = A - B = (Ax - Bx, Ay - By), BC = C - B = (Cx - Bx, Cy - By)
    // ∠ABCが180°未満 <=> AB × BC > 0
    // なぜならAB × BC = |AB||BC|sinθで、sinθ > 0 <=> 0° < θ < 180°が成り立つから
    // AB × BC = (Bx - Ax)(Cy - By) - (By - Ay)(Cx - Bx)
    // これが> 0なら頂点Bの内角は180°未満
    // 全頂点でこれをチェックする
    // 頂点A: DA × AB > 0, 頂点B: AB × BC > 0, 頂点C: BC × CD > 0, 頂点D: CD × DA > 0
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    // DAB, ABC, BCD, CDA
    if (cross(Dx, Dy, Ax, Ay, Bx, By) <= 0 ||
        cross(Ax, Ay, Bx, By, Cx, Cy) <= 0 ||
        cross(Bx, By, Cx, Cy, Dx, Dy) <= 0 ||
        cross(Cx, Cy, Dx, Dy, Ax, Ay) <= 0) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
