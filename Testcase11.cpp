#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX 255
int mainte11() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	float** g = (float**)calloc(a,sizeof(*g));
	for (int i = 0; i < a; i++) {
		g[i] = (float*)calloc(b , sizeof(float));
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf_s("%f", &g[i][j]);
		}
	}
	// Gia tri lon nhat tren cot 0 la: 9
	for (int j = 0; j < b; j++) {
		printf("Gia tri lon nhat tren cot %d la: ",j);
		float max = INT_MIN;
		for (int i = 0; i < a; i++) {
			if (max < g[i][j]) {
				max = g[i][j];
			}
		}
		printf("%g\n", max);
	}
	for (int i = 0; i < a; i++) {
		free(g[i]);
	}
	free(g);
	return 0;
}