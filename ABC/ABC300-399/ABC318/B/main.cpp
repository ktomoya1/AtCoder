#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	// int N;
	// cin >> N;

	// vector<int> A(N), B(N), C(N), D(N);
	// for (int i = 0; i < N; ++i) cin >> A[i] >> B[i] >> C[i] >> D[i];
	// // 愚直な計算
	// vector<vector<int>> Sheet(100, vector<int>(100, 0));
	// for (int i = 0; i < N; ++i) {
	// 	for (int j = C[i]; j < D[i]; ++j) {
	// 		for (int k = A[i]; k < B[i]; ++k) {
	// 			++Sheet[j][k];
	// 		}
	// 	}
	// }
	// int s = 0;
	// for (int i = 0; i < 100; ++i) {
	// 	for (int j = 0; j < 100; ++j) {
	// 		if (Sheet[i][j] > 0)
	// 			++s;
	// 	}
	// }
	// cout << s << endl;

	// // いもす法を使った解き方
	// // 累積和ってデータ型何使うんだっけ？２つ使う気がする
	// // -1, +1をチェックするためのものと累積和をとるためのもの
	// vector<vector<int>> A(101, vector<int>(101, 0));
	// for (int i = 0; i < N; ++i) {
	// 	int a, b, c, d; // a <= x <= b, c <= y <= d
	// 	cin >> a >> b >> c >> d;
	// 	A[c][a] += 1; // 左上
	// 	A[c][b] -= 1; // 右上
	// 	A[d][a] -= 1; // 左下
	// 	A[d][b] += 1; // 右下
	// }

	// // 横に累積和をとる
	// vector<vector<int>> S(101, vector<int>(101, 0));
	// for (int i = 0; i < 100; ++i) {
	// 	S[i][0] = A[i][0];
	// 	for (int j = 0; j < 100; ++j) S[i][j + 1] = S[i][j] + A[i][j + 1];
	// }

	// // 縦に累積和をとる
	// for (int j = 0; j < 100; ++j) {
	// 	for (int i = 0; i < 100; ++i) S[i + 1][j] = S[i][j] + S[i + 1][j];
	// }

	// int s = 0;
	// for (int i = 0; i < 100; ++i) {
	// 	for (int j = 0; j < 100; ++j) {
	// 		if (S[i][j] > 0) ++s;
	// 	}
	// }
	// cout << s << endl;

	int n, ans = 0;
    cin >> n;
    vector<vector<int>> imos(101,vector<int>(101,0));
    for(int i=0;i<n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        imos[a][c]++;
        imos[a][d]--;
        imos[b][c]--;
        imos[b][d]++;
    }
    for(int i=0;i<101;i++) for(int j=0;j<100;j++) imos[i][j+1] += imos[i][j];
    for(int i=0;i<100;i++) for(int j=0;j<101;j++) imos[i+1][j] += imos[i][j];
    for(int i=0;i<100;i++) for(int j=0;j<100;j++) if(imos[i][j]>0) ans++;
    cout << ans << '\n';
    return 0;
}