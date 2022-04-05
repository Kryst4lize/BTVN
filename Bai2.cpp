#include "Bai2.h"
#include<iostream>
using namespace std;
inum inum::operator +(inum g) {
	inum sum(a + g.getReal(), b + g.getImg());
	return sum;
}
inum inum::operator -(inum g) {
	inum sum(a - g.getReal(), b - g.getImg());
	return sum;
}
inum inum::operator *(inum g) {
	inum multiply(a * g.getReal() - b * g.getImg(), a * g.getImg() + b * g.getReal());
	return multiply;
}
inum inum::operator /(inum g) {
	inum divided((a * g.getReal() + b * g.getImg()) / (pow(g.getReal(), 2) + pow(g.getImg(), 2)), (-a * g.getImg() + b * g.getReal()) / (pow(g.getReal(), 2) + pow(g.getImg(), 2)));
	return divided;
}
void inum::print() {
	cout << a;
	if (b > 0) {
		cout << "+" << b << "i" << endl;
	}
	else {
		cout << b << "i" << endl;
	}
}
double inum::getImg() {
	return b;
}
double inum::getReal() {
	return a;
}
void inum::setImg(double b) {
	this->b = b;
}
void inum::setReal(double a) {
	this->a = a;
}