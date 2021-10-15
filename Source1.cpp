#include<iostream>
using namespace std;
class Fraction {
private:
	int x;
	int y;
public:
	Fraction() :x(0), y(0) {}
	Fraction(int x, int y) :x(x), y(y) {}
	friend Fraction operator + (Fraction& a, Fraction& b);
	friend Fraction operator - (Fraction& a, Fraction& b);
	friend Fraction operator * (Fraction& a, Fraction& b);
	friend Fraction operator / (Fraction& a, Fraction& b);
	friend bool operator == (Fraction& a, Fraction& b);
	int gcd(int x, int y) {
		if (y == 0) { return x; }
		gcd(y, x % y);
	}
	void reduce() {
		{
			int d;
			d = gcd(this->x, this->y);
			this->x = this->x / d;
			this->y = this->y / d;
		}
	}
	void display()
	{
		cout << x << "/" << y;
	}
	void setX(int x)
	{
		this->x = x;
	}
	int getX()
	{
		return x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getY()
	{
		return y;
	}
};
Fraction operator + (Fraction& a, Fraction& b) {
	int x = a.x * b.y + a.y * b.x;
	int y = a.y * b.y;
	Fraction temps(x, y);
	return temps;
}
Fraction operator - (Fraction& a, Fraction& b) {
	int x = a.x * b.y - a.y * b.x;
	int y = a.y * b.y;
	Fraction temps(x, y);
	return temps;
}
Fraction operator * (Fraction& a, Fraction& b) {
	int x = a.x * b.x;
	int y = a.y * b.y;
	Fraction temps(x, y);
	return temps;
}
Fraction operator / (Fraction& a, Fraction& b) {
	int x = a.x * b.y;
	int y = a.y * b.x;
	Fraction temps(x, y);
	return temps;
}
bool operator == (Fraction& a, Fraction& b) {
	if (a.x * b.y == a.y * b.x) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	Fraction a(1, 4);
	Fraction b(1, 2);
	Fraction c;
	c = a + b;
	c.display();
	return 0;
}
