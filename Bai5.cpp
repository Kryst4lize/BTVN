#include "Bai5.h"
#include<iostream>
#include<math.h>
#include<numbers>
# define PI           3.14159265358979323846
using namespace std;
double point::getX() {
	return x;
}
double point::getY() {
	return y;
}
void point::setX(double x) {
	this->x = x;
}
void point::setY(double y) {
	this->y = y;
}
void triangle::setTriangle(point A, point B, point C) {
	this->A = A;
	this->B = B;
	this->C = C;
	setCenter();
}
void triangle::setCenter() {
	G.setX((A.getX() + B.getX() + C.getX() / 3));
	G.setY((A.getY() + B.getY() + C.getY() / 3));
}
void triangle::translation(double xmove, double ymove) { //tinh tien
	A.setX(A.getX() + xmove);
	A.setY(A.getY() + ymove);
	B.setX(B.getX() + xmove);
	B.setY(B.getY() + ymove);
	C.setX(C.getX() + xmove);
	C.setY(C.getY() + ymove);
	setCenter();
}
void triangle::input() {
	cout << "Nhap toa do 3 diem (x,y) ";
	double x, y;
	cin >> x >> y;
	A.setX(x); A.setY(y);
	cin >> x >> y;
	B.setX(x); B.setY(y);
	cin >> x >> y;
	C.setX(x); C.setY(y);
	setCenter();
}
void triangle::output() {
	cout << "Toa do cua tam giac lan luot la :\n";
	cout << "A(x,y): (" << A.getX() << "," << A.getY() << ")" << endl;
	cout << "B(x,y): (" << B.getX() << "," << B.getY() << ")" << endl;
	cout << "C(x,y): (" << C.getX() << "," << C.getY() << ")" << endl;
}
void triangle::rotation(double theta) {
	cout << "Da xoay hinh tam giac theo trong tam G" << endl;
	A.setX(G.getX() + (A.getX() - G.getX()) * cos(theta / 180 * PI) - (A.getY() - G.getY()) * sin(theta / 180 * PI));
	A.setY(G.getY() + (A.getX() - G.getX()) * sin(theta / 180 * PI) + (A.getY() + G.getY()) * cos(theta / 180 * PI));
	B.setX(G.getX() + (B.getX() - G.getX()) * cos(theta / 180 * PI) - (B.getY() - G.getY()) * sin(theta / 180 * PI));
	B.setY(G.getY() + (B.getX() - G.getX()) * sin(theta / 180 * PI) + (B.getY() + G.getY()) * cos(theta / 180 * PI));
	C.setX(G.getX() + (C.getX() - G.getX()) * cos(theta / 180 * PI) - (C.getY() - G.getY()) * sin(theta / 180 * PI));
	C.setY(G.getY() + (C.getX() - C.getX()) * sin(theta / 180 * PI) + (C.getY() + G.getY()) * cos(theta / 180 * PI));
	setCenter();
}
void triangle::magnified(double scale) { //phong to hay thu nho phu thuoc vao scale , thu nho neu scale<1, phong to neu scale>1
	A.setX(A.getX() * scale);
	A.setY(A.getY() * scale);
	B.setX(B.getX() * scale);
	B.setY(B.getY() * scale);
	C.setX(C.getX() * scale);
	C.setY(C.getY() * scale);
	setCenter();
}