#include<string>
#include<sstream>
#include<vector>
#include<list>
#include<set>
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
#include<sstream>
using namespace std;

class fraction {
public:
	int x, y;
	fraction() :x(0), y(0) {}
	fraction(int x, int y) :x(x), y(y) {}
	void print() {
		int check = 0;
		//check
		if (x > 0) {
			check++;
		}
		if (y > 0) {
			check++;
		}
		if (check % 2 == 1) {
			cout << "-";
		}
		int a = abs(x), b = abs(y);
		if (b == 1 || a == 0) {
			cout << a << endl;
		}
		else {
			cout << a << "/" << b << endl;
		}
	}
	void simplified() {
		int a = abs(x), b = abs(y);
		while (b != 0) {
			int temps = a % b;
			a = b;
			b = temps;
		}
		x /= a;
		y /= a;
		print();
	}
	void max(fraction a, fraction b) {
		if (1.0 * a.x / a.y > 1.0 * b.x / b.y) {
			a.simplified();
		}
		else {
			b.simplified();
		}
	}
	void calculate(fraction a, fraction b) {
		fraction plus(a.x * b.y + b.x * a.y, a.y * b.y);
		plus.simplified();
		fraction minus(a.x * b.y - b.x * a.y, a.y * b.y);
		minus.simplified();
		fraction multiply(a.x * b.x, a.y * b.y);
		multiply.simplified();
		fraction divided(a.x * b.y, a.y * b.x);
		divided.simplified();
	}
};


int main() {
	return 0;
}