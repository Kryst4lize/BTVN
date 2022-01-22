#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int mainte5() {
	int n, s,k;
	const int mod = 1000000007;
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf_s("%d", &n);
		fflush(stdin);
		scanf_s("%d", &s);
		int in4[10000];
		int in7[10000];
		int sum = 0;
		int check[11] = { 1,0,0,0,0,0,0,0,0,0,0 };
		in4[0] = 0;
		in7[0] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = s; j > 0; j--) {
				check[j] = check[j - 1] % mod;
			}
			in7[i] = (in7[i - 1] + in4[i - 1]) % mod;
			for (int j = 1; j < s; j++) {
				sum += check[j];
				sum = sum % mod;
			}
			check[0] = in7[i];
			in4[i] = sum;
			sum = 0;
		}
		int sum2 = (in4[n - 1] + in7[n - 1]) % mod;
		printf("%d\n", sum2);
	}
	return 0;
}