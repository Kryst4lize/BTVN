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
#include<random>
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
class PhanSo {
private:
	int x, y;
public:
	PhanSo() :x(0), y(0) {}
	PhanSo(int x, int y) :x(x), y(y) {}
	int  getTuSo() {
		return x;
	}
	int getMauSo() {
		return y;
	}
	void setTuSo(int x) {
		this->x = x;
	}
	void setMauSo(int y) {
		this->y = y;
	}
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
	PhanSo operator +(PhanSo b) {
		PhanSo plus(x * b.getMauSo() + b.getTuSo() * y, y * b.getMauSo());
		plus.simplified();
		return plus;
	}
	PhanSo operator -(PhanSo b) {
		PhanSo minus(x * b.getMauSo() - b.getTuSo() * y, y * b.getMauSo());
		minus.simplified();
		return minus;
	}
	PhanSo operator *(PhanSo b) {
		PhanSo multiply(x * b.getTuSo(), y * b.getMauSo());
		multiply.simplified();
		return multiply;
	}
	PhanSo operator /(PhanSo b) {
		PhanSo divided(x * b.getMauSo(), y * b.getTuSo());
		divided.simplified();
		return divided;
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
class cArray {
private:
	vector<int>array;
	int n;
public:
	cArray() {}
	cArray(int n) {
		random_device rd;
		mt19937 ak(rd());
		uniform_real_distribution<double> mt(-40000, 40000);
		array.resize(n);
		for (int j = 0; j < n; j++) {
			int k = mt(ak);
			array[j] = k;
		}
	}
	bool isDescend() {
		for (int i = 0; i < n-1; i++) {
			if (array[i] < array[i + 1]) {
				return false;
			}
		}
		return true;
	}
	int maxNegative() {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (array[i] < 0 && count == 0) {
				count = array[i];
			}
			if (count < 0 && array[i] < count) {
				array[i] = count;
			}
		}
	}
};
class inum {
private:
	double a, b;
public:
	inum(double a = 0, double b = 0) :a(a), b(b) {}
	void setReal(double a) {
		this->a = a;
	}
	void setImg(double b) {
		this->b = b;
	}
	double getReal() {
		return a;
	}
	double getImg() {
		return b;
	}
	void print() {
		cout << a;		
		if (b > 0) {
			cout << "+" << b << "i" << endl;
		}
		else {
			cout << b << "i" << endl;
		}
	}
	inum operator +(inum g) {
		inum sum(a + g.getReal(), b + g.getImg());
		return sum;
	}
	inum operator -(inum g) {
		inum sum(a - g.getReal(), b - g.getImg());
		return sum;
	}
	inum operator *(inum g) {
		inum multiply(a * g.getReal() - b * g.getImg(), a * g.getImg() + b * g.getReal());
		return multiply;
	}
	inum operator /(inum g) {
		inum sum((a * g.getReal() + b * g.getImg())/(pow(g.getReal(),2)+pow(g.getImg(),2)), (-a * g.getImg() + b * g.getReal())/ (pow(g.getReal(), 2) + pow(g.getImg(), 2)));
		return sum;
	}
};
class candidate {
private:
	int MSSV;
	string date;
	double math;
	double english;
	double literature;
public:
	candidate() {}
	int getMSSV() {
		return MSSV;
	}
	double getMath() {
		return math;
	}
	double getEnglish() {
		return english;
	}
	double getLiterature() {
		return literature;
	}
	string getDate() {
		return date;
	}
	void setMath(double a) {
		math = a;
	}
	void setEnglish(double a) {
		english = a;
	}
	void setLiterature(double a) {
		literature = a;
	}
	void setMSSV(int a) {
		MSSV = a;
	}
	void setDate(string a) {
		date = a;
	}
	void TestCandidate() {
		int n;
		cin >> n;
		vector<candidate>a(n);
		for (int i = 0; i < n; i++) {

		}
	}
};
int mainte12() {
	inum a(1, 5);
	inum b(0, 1);
	inum c = a / b;
	c.print();
	return 0;
}