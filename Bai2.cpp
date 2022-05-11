#include<string>
#include<sstream>
#include<vector>
#include<list>
#include<set>
#include<stack>
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
#include<tuple>
#include<fstream>
using namespace std;
#include "Bai2.h"
void rectangle::input() {
	cout << "Nhap 3 diem cua tam giac (x,y)" << endl;
	cout << "Nhap toa do cua diem A :";
	cin >> A.x >> A.y;
	cout << "Nhap toa do cua diem B :";
	cin >> B.x >> B.y;
	cout << "Nhap toa do cua diem C :";
	cin >> C.x >> C.y;
}
void rectangle::output() {
	cout << "Day la hinh tam giac " << endl;
	cout << "Toa do cua A la : (" << A.x << "," << A.y << ")\n";
	cout << "Toa do cua B la : (" << B.x << "," << B.y << ")\n";
	cout << "Toa do cua C la : (" << C.x << "," << C.y << ")\n";
}
void rectangle::move() {
	int a, b;
	cout << "Nhap do dich chuyen vector cua hinh: ";
	cin >> a >> b;
	cout << "Da tinh tien thanh cong.\n";
	A.x += a; A.y += b;
	B.x += a; B.y += b;
	C.x += a; C.y += b;
}
void quadrilateral::input() {
	cout << "Nhap 4 diem cua hinh tu giac (x,y)" << endl;
	cout << "Nhap toa do cua diem A :";
	cin >> A.x >> A.y;
	cout << "Nhap toa do cua diem B :";
	cin >> B.x >> B.y;
	cout << "Nhap toa do cua diem C :";
	cin >> C.x >> C.y;
	cout << "Nhap toa do cua diem D :";
	cin >> D.x >> D.y;
}
void quadrilateral::output() {
	cout << "Day la hinh tu giac ABCD " << endl;
	cout << "Toa do cua A la : (" << A.x << "," << A.y << ")\n";
	cout << "Toa do cua B la : (" << B.x << "," << B.y << ")\n";
	cout << "Toa do cua C la : (" << C.x << "," << C.y << ")\n";
	cout << "Toa do cua D la : (" << D.x << "," << D.y << ")\n";
}
void quadrilateral::move() {
	int a, b;
	cout << "Nhap do dich chuyen vector cua hinh: ";
	cin >> a >> b;
	cout << "Da tinh tien thanh cong.\n";
	A.x += a; A.y += b;
	B.x += a; B.y += b;
	C.x += a; C.y += b;
	D.x += a; D.y += b;
}
void square::input() {
	cout << "Nhap 2 diem cua hinh vuong (x,y)" << endl;
	cout << "Nhap toa do cua diem A :";
	cin >> A.x >> A.y;
	cout << "Nhap toa do cua diem B :";
	cin >> B.x >> B.y;
	int a = A.x - B.x, b = A.y - B.y, flag = 0;
	cout << "Ban muon lay diem BC co vector (" << -b << "," << a << ") hay (" << b << "," << -a << ") (1|2): ";
	cin >> flag;
	if (flag == 1) {
		C.x = B.x - b;
		C.y = B.y + a;
		D.x = A.x - b;
		D.y = A.y + a;
	}
	else {
		C.x = B.x + b;
		C.y = B.y - a;
		D.x = A.x + b;
		D.y = A.y - a;
	}
}
void square::output() {
	cout << "Day la hinh vuong ABCD " << endl;
	cout << "Toa do cua A la : (" << A.x << "," << A.y << ")\n";
	cout << "Toa do cua B la : (" << B.x << "," << B.y << ")\n";
	cout << "Toa do cua C la : (" << C.x << "," << C.y << ")\n";
	cout << "Toa do cua D la : (" << D.x << "," << D.y << ")\n";
}
void square::move() {
	int a, b;
	cout << "Nhap do dich chuyen vector cua hinh: ";
	cin >> a >> b;
	cout << "Da tinh tien thanh cong.\n";
	A.x += a; A.y += b;
	B.x += a; B.y += b;
	C.x += a; C.y += b;
	D.x += a; D.y += b;
}
void parallelogram::input() {
	cout << "Nhap 3 diem cua hinh binh hanh (x,y)" << endl;
	cout << "Nhap toa do cua diem A :";
	cin >> A.x >> A.y;
	cout << "Nhap toa do cua diem B :";
	cin >> B.x >> B.y;
	cout << "Nhap toa do cua diem C :";
	cin >> C.x >> C.y;
	D.x = A.x + (C.x - B.x);
	D.y = A.y + (C.y - B.y);
}
void parallelogram::output() {
	cout << "Day la hinh tu giac ABCD " << endl;
	cout << "Toa do cua A la : (" << A.x << "," << A.y << ")\n";
	cout << "Toa do cua B la : (" << B.x << "," << B.y << ")\n";
	cout << "Toa do cua C la : (" << C.x << "," << C.y << ")\n";
	cout << "Toa do cua D la : (" << D.x << "," << D.y << ")\n";
}
void parallelogram::move() {
	int a, b;
	cout << "Nhap do dich chuyen vector cua hinh: ";
	cin >> a >> b;
	cout << "Da tinh tien thanh cong.\n";
	A.x += a; A.y += b;
	B.x += a; B.y += b;
	C.x += a; C.y += b;
	D.x += a; D.y += b;
}
void bai2() {
	string ss = "No";
	polygon* b=NULL;
	cout << "Ban muon nhap, in, tinh tien hinh da co hay ket thuc chuong trinh (N|I|TT|KT): ";
	cin >> ss;
	while (ss != "KT") {
		while (ss != "N" && ss != "I" && ss != "TT" && ss != "KT") {
			cout << "Nhap sai cu phap, moi nhap chuyen lai (N|I|TT|KT): ";
			cin >> ss;
		}
		if (ss == "N") {
			string a;
			if (b!=NULL)delete b;
			cout << "(R la Rectangle, Q la Quadrilateral, P la Parallelogram, S la Square)" << endl;
			cout << "Moi ban nhap loai hinh (R|Q|P|S): ";
			cin >> a;
			while (a != "R" && a != "Q" && a != "P" && a != "S") {
				cout << "Nhap sai cu phap, moi nhap chuyen lai (R|P|Q|S): ";
				cin >> a;
			}
			if (a == "R") {
				b = new rectangle();
			}
			else if (a == "Q") {
				b = new quadrilateral();
			}
			else if (a == "P") {
				b = new parallelogram();
			}
			else if (a == "S") {
				b = new square();
			}
			b->input();
		}
		else if (ss == "I") {
			b->output();
		}
		else if (ss == "TT") {
			if (b == nullptr || b == NULL) {
				cout << "Chua tao hinh: " << endl;
			}
			else {
				b->move();
			}
		}
		else if (ss == "KT") {
			delete b;
			cout << "Ket thuc chuong trinh. ";
			break;
		}
		cout << "Ban muon nhap, in, tinh tien hinh da co hay ket thuc chuong trinh (N|I|TT|KT): ";
		cin >> ss;
	}
}