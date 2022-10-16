#include <stdio.h>
#include <math.h>
#include <string.h>
const long long MOD = 1e9 + 7;
int maindp () {
	int s, n, k;
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf_s("%d %d", &n, &s);
		n--;
		int dp[10005][15];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < s; j++) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < s; j++) {
				dp[i + 1][0] += dp[i][j];
				dp[i + 1][0] %= MOD;
				if (j + 1 < s) {
					dp[i + 1][j + 1] = dp[i][j];
					dp[i + 1][j + 1] %= MOD;
				}
			}
		}
		int res = 0;
		for (int j = 0; j < s; j++) {
			res += dp[n][j];
			res %= MOD;
		}
		printf("%d\n", res);
	}
	return 0;
}