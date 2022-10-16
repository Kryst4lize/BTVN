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
//closest pair geeksforgeek
using namespace std;
struct PhanSo {
	int x, y;
	PhanSo operator / (PhanSo a) {
		PhanSo temps;
		temps.y = this->y * a.x;
		temps.x = this->x * a.y;
		return temps;
	}
	PhanSo operator + (PhanSo a) {
		PhanSo temps;
		temps.y = this->y * a.y;
		temps.x = this->x * a.y + this->y * a.x;
		return temps;
	}
	PhanSo operator * (PhanSo a) {
		PhanSo temps;
		temps.x = this->x * a.y;
		temps.y = this->y * a.x;
		return temps;
	}
};
int GDC(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (b == 0) { return a; }
	else {
		return GDC(b, a % b);
	}
}
void Nhap(PhanSo& a) {
	cin >> a.x >> a.y;
}
PhanSo Nhap() {
	PhanSo temps;
	cin >> temps.x >> temps.y;
	return temps;
}
PhanSo Chia(PhanSo a, PhanSo b) {
	int flag1 = 0;
	PhanSo c = a / b;
	if (c.x == 0) {
		cout << "0" << endl;
	}
	else {
		int flag1 = 0;
		if (c.x < 0) { flag1++; }
		if (c.y < 0) { flag1++; }
		int g = GDC(abs(c.x), abs(c.y));
		if (flag1 == 1) { cout << "-"; }
		if (g == abs(c.y)) {
			cout << abs(c.x) / abs(g) << endl;
		}
		else {
			cout << abs(c.x) / g << "/" << abs(c.y) / g << endl;
		}
	}
	return c;
}
void Xuat(PhanSo a) {}
int SoSanh(PhanSo a, PhanSo b) {
	double c = double(a.x) / double(a.y) - double(b.x) / double(b.y);
	if (c < 0) { return -1; }
	if (c == 0) { return 0; }
	if (c > 0) { return 1; }
}
int mainstr() {
	PhanSo a, b;
	Nhap(a);
	b = Nhap();
	Xuat(Chia(a, b));
	return 0;
}