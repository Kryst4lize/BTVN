#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int mainte5 () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N=1, C=1, R=1, K=0;
	vector<vector<int>>a(R);
	while (true) {
		//input
		cin >> N >> R >> C >> K;
		if (N == 0 && R == 0 && C == 0 && K == 0) { break; }
		a.resize(R);
		for (int i = 0; i < R; i++) {
			a[i].resize(C);
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin>>a[i][j];
			}
		}
		//process
		for (int i = 0; i < K; i++) {
			vector<vector<int>>b(a);
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (a[i][j] == 0) {
						if ((j - 1 > -1 && a[i][j - 1] == N - 1) || (j + 1 < C && a[i][j + 1] == N - 1) || (i + 1 < R && a[i + 1][j] == N - 1) || (i - 1 > -1 && a[i - 1][j] == N - 1)) {
							b[i][j] = N - 1;
						}
					}
					else {
						if ((j - 1 > -1 && a[i][j - 1] == a[i][j] - 1) || (j + 1 < C && a[i][j + 1] == a[i][j] - 1) || (i + 1 < R && a[i + 1][j] == a[i][j] - 1) || (i - 1 > -1 && a[i - 1][j] == a[i][j] - 1)) {
							b[i][j] = a[i][j] - 1;
						}
					}
				}
			}
			a = b;
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}