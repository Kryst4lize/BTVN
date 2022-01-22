#include <stdio.h>
#include <math.h>
#include <string.h>
const long long MOD = 1e9 + 7;
long long pw2[10005];
long long dp[10005][15];
int main () {
    // freopen("input.txt", "r", stdin);
    pw2[0] = 1;
    for (int i = 1; i <= 10000; i++) {
        pw2[i] = pw2[i - 1] * 2;
        pw2[i] %= MOD;
    }
    int t;
    scanf_s("%d", &t);
    for (int z = 1; z <= t; z++) {
        int n, s;
        scanf_s("%d %d", &n, &s);
        n--;
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
        long long res = 0;
        for (int i = 0; i < s; i++) {
            res += dp[n][i];
            res %= MOD;
        }
        printf("%lld\n", res);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                dp[i][j] = 0;
            }
        }
    }
    return 0;
}