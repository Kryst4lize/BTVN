#pragma once
class point 
{
private:
	double x, y;
	
public:
	point(double x = 0, double y = 0):x(x),y(y) {}
	~point(){}
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
};
class triangle{
private:
	point A, B, C, G; //G was the center of triangle
public:
	triangle(point A, point B, point C):A(A),B(B),C(C) {
		setCenter();
	}
	triangle() {}
	void setCenter();
	void input();
	void output();
	void setTriangle(point A, point B, point C); 
	void translation(double xmove, double ymove);
	void rotation(double theta);
	void magnified(double scale);
};

