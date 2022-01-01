#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<climits>
#include<sstream>
#include<bitset>
#include<fstream>
#include<string.h>
#include <stdio.h>
#include<cstring>
#define MAXR 100
#define MAXC 100
using namespace std;
void NhapMaTran(double a[][100],int&m ,int & n) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}
void Multiplication(double a[][100], double b[][100],int m,int n,int p,int q) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}
int main() {
    double a[100][100],b[100][100];
    int n = 0, m = 0, p = 0, q = 0;
    NhapMaTran(a, m, n);
    NhapMaTran(b, p, q);
    Multiplication(a, b, m, n, p, q);
    return 0;
}
