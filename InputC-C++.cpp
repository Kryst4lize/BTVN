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
void NhapMaTran(float  a[][100],int&m ,int & n) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}
bool frobenius(double a[][100], int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j][i] != 0 && i > j) {
                return false;
            }
            if (a[j][i] != 1 && i == j) {
                return false;
            }
            if (a[j][i] != 0 && i < j) {
                flag++; break;
            }
        }
    }
    if (flag > 1) { return false; }
    else { return true; }
}
double trace(double a[][100], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][i];
    }
    return sum;
}
bool Diagonal(double a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (a[i][j] != 0 && i != j) {
                return false;
            }

        }
    }
    return true;
}
void Multiplication(float a[][100], float b[][100],int m,int n,int p,int q) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            float  sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}
int maincc() {
    float a[100][100], b[100][100];
    int n = 0, m = 0, p = 0, q = 0;
    NhapMaTran(a, m, n);
    NhapMaTran(b, p, q);
    Multiplication(a, b, m, n, p, q);
    return 0;
}
#define ll long long
ll divide=1000000007;
vector<long long >check(3);
int CeilIndex(vector<int>&v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int LongestIncreasingSubsequenceLength(vector<int>& v)
{
    if (v.size() == 0)
        return 0;
    std::vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
    return length;
}

int mainC()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << LongestIncreasingSubsequenceLength(v) << '\n';
    return 0;
}