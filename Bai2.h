#pragma once
class inum {
private:
	double a, b;
public:
	inum(double a = 0, double b = 0) :a(a), b(b) {}
	~inum(){}
	void setReal(double a);
	void setImg(double b);
	double getReal();
	double getImg();
	void print();
	inum operator +(inum g);
	inum operator -(inum g);
	inum operator *(inum g);
	inum operator /(inum g);
};

