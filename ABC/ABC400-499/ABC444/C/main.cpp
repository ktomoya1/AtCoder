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

// WAの原因: ソートした数列がmin+maxになる法則性に気づかなかった
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // a1,a2,...,anはソートしても問題ない
    // 全てのAtCoderりこが２本に分かれた場合とAtCoderりこが分かれなかった場合の2通りでLが変化する
    // 1. 2本に分かれる場合->Nが必ず偶数で、a1+an=Lとすると、(a2,an-1),(a3,an-2),...,(an/2,an/2+1)
    // のペア全てがa1+anと等しければLは条件を満たす
    // 2. 分かれなかったAtCoderりこが存在する場合:最も長いAtCoderりこが2本に分かれな買ったAtCoderりこ
    // なので、L=an, an未満のAtCoderりこについて1と同様に判定を行う
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    vector<ll> L(2);
    if (n % 2 == 0) {
        L[0] = a[0] + a[n - 1];
        for (int i = 1; i < n / 2; i++) {
            if (L[0] != a[i] + a[n - 1 - i]) {
                L[0] = 0;
                break;
            }
        }
    }

    L[1] = a[n - 1];
    int j = n - 1;
    while (j >= 0 && a[j] == L[1]) j--;
    if (j < 0) {
        ;
    } else if ((j + 1) % 2 != 0) {
        L[1] = 0;
    } else {
        for (int i = 0; i <= j / 2; i++) {
            if (L[1] != a[i] + a[j - i]) {
                L[1] = 0;
                break;
            }
        }
    }
    if (L[0] > L[1]) swap(L[0], L[1]);
    if (L[0]) cout << L[0] << ' ' << L[1] << "\n";
    else cout << L[1] << "\n";
    return 0;
}
