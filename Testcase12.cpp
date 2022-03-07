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
int func1(int);
// float func1(int); false because same parameter, only differ in return type
int func1(float);
// void func1(int = 0, int); false because default parameter have to be in the end of list 
void func2(int, int = 0);
void func2(int);
void func2(float);
void func(int i, int j = 0) {
	cout << "Songuyen:" << i << " " << j << endl;
}
void func(float i = 0, float j = 0) {
	cout << "Sothuc:" << i << " " << j << endl;
}
void tomorrow() {
	int day, month, year;
	cout << "Nhap theo thu tu lan luot: ngay-thang-nam" << endl;
	cin >> day >> month >> year;
	map<int, int>months = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
	if (year % 4 == 0) {
		months[2]++;
	}
	if (day >= months[month]) {
		day =day+ 1-months[month];
		month++;
	}
	if (month > 12) {
		month =(month+1)%12;
		year++;
	}
	cout << day << "/" << month << "/" << year << endl;
}
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

class student {
private:
	string id;
	string name;
	string gender;
	double math, physic, chemistry;
public:
	student(){}
	student(double math, double physic, double chemistry) :math(math), physic(physic), chemistry(chemistry) {}
	void input() {
		cin >> id;
		cin.ignore();
		getline(cin, name);
		cin >> gender;
		cin >>math >> physic >> chemistry;
	}
	void output() {
		cout << "Ma sinh vien la" << id << endl;
		cout << "Ten sinh vien la" << name << endl;
		cout << "Diem toan cua sinh vien la" << math << endl;
		cout << "Diem ly cua sinh vien la" << physic << endl;
		cout << "Diem hoa cua sinh vien la" << chemistry << endl;
		cout << "Diem trung binh cua sinh vien la" << (math+physic+chemistry)/3 << endl;
	}
};
int mainte12() {
	string s = "Fred/First/014";
	stringstream ss;
	ss<<s;
	string a;
	while (getline(ss, a, '/')) {
	}
	cout << a;
	return 0;
}