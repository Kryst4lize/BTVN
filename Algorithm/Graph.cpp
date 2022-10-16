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
#include<utility>
using namespace std;
struct Point {
	Point():x(0),y(0){}
	Point(double x, double y) :x(x), y(y) {}
	double x;
	double y;
};
struct vector2 { //VOZer
	Point a;
	Point b;
	vector2(Point a, Point b):a(a),b(b) {}
};
int CCW(Point a, Point b, Point c) { //consecutive order
	/*>0 mean counter clockwise
	  <0 mean clockwise
	  =0 mean linear
	*/
	return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}

bool intersect(vector2 v1, vector2 v2) {
	if (CCW(v2.a, v2.b, v1.a) * CCW(v2.a, v2.b, v1.b) <= 0) {
		if (CCW(v1.a, v1.b, v2.a) * CCW(v1.a, v1.b, v2.b) <= 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else return false;
}
double Area(vector<Point>check) {
	double sum = 0;
	sum -= 0.5 * double(abs(check[0].y + check[check.size() - 1].y) * (check[check.size() - 1].x - check[0].x));
	for (int i = 0; i < check.size() - 1; i++) {
		sum += 0.5 * double(abs(check[i].y + check[i + 1].y) * (check[i + 1].x - check[i].x));
	}
	return sum;
}
int maingr() {
	int n;
	cin >> n;
	vector<Point>check(n);
	for (int i = 0; i < n; i++) {
		cin >> check[i].x >> check[i].y;
	}
	return 0;
}