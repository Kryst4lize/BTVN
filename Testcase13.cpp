#include<string>
#include<sstream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<climits>
#include<bitset>
#include<fstream>
#include<chrono>
#include<functional>
#include<utility>
#include<limits>
#include<vector>
#include<random>
#include<sstream>
#define ll long long 
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	vector<int>arr(n + 1);
	vector<int>sum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			sum[i] += sum[i - 1] + arr[i] + 1;
		}
		else {
			sum[i] += sum[i - 1] + arr[i];
		}
	}
	vector<vector<int>>dp(n + 1);
	for (int i = 0; i <= n; i++) {
		dp[i].resize(m + 2);
	}
	dp[0][0] = 1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {

				if (arr[i] + j > m) {
					dp[i][j] = 0;
				}
				else {
					for (int k = sum[i-1]; k < j; k++) {
						dp[i][j] += dp[i - 1][k];
					}
				}

			
		}
	}
	int res = 0;
	for (auto a : dp) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < m+2; i++) {
		res += dp[n][i];
	}
	cout << res;
	return 0;
}