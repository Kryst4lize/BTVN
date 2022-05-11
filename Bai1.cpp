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
#include "Bai1.h"

void book::input() {
	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, name);
	cout << "Nhap nam xuat ban sach: ";
	cin >> year;
	while (year > 2022 || year < 0) {
		cout << "Nam xuat ban khong hop le,vui long nhap lai : ";
		cin >> year;
	}
	cin.ignore();
	cout << "Nhap ten tac gia: ";
	getline(cin, author);
}
void book::output() {
	cout << "Ten sach : " << name << endl;
	cout << "Nam xuat ban: " << year << endl;
	cout << "Tac gia: " << author << endl;
}
void SGK::input() {
	book::input();
}

void SGK::output() {
	cout << "The loai sach: " << type << endl;
	book::output();
}
void TT::input() {
	book::input();
}
void TT::output() {
	cout << "The loai sach: " << type << endl;
	book::output();
}
void TC::input() {
	book::input();
}
void TC::output() {
	cout << "The loai sach: " << type << endl;
	book::output();
}
void manage::input() {
	string a;
	cout << "Nhap loai sach (TT|TC|SGK) : ";
	cin >> a;
	while (a != "TT" && a != "TC" && a != "SGK") {
		cout << "Loai sach khong dung, moi nhap lai : ";
		cin >> a;
	}
	if (a == "SGK") {
		arr.push_back(new SGK());
		arr[arr.size() - 1]->input();
	}
	else if (a == "TC") {
		arr.push_back(new TC());
		arr[arr.size() - 1]->input();
	}
	else if (a == "TT") {
		arr.push_back(new TT());
		arr[arr.size() - 1]->input();
	}
}
void manage::output() {
	cout << "Co " << arr.size() << " cuon sach dang quan ly :" << endl;
	for (int i = 0; i < arr.size(); i++) {
		arr[i]->output();
	}
}
void manage::remove() {
	int index;
	cout << "Ban muon xoa cuon o thu tu nao: (co tong cong " << arr.size() << " cuon sach): ";
	cin >> index;
	if (index <= arr.size() && index >= 1) {
		delete arr[index - 1];
		for (int i = index - 1; i < arr.size() - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr.resize(arr.size() - 1);
		cout << "Xoa thanh cong " << endl;
	}
}
void bai1()
{
	string a="XXX";
	manage b;
	cout << "Ban muon nhap, in, xoa, thoat (N|I|X|T): ";
	cin >> a;
	while (a != "T") {
		while (a != "N" && a != "I" && a != "X" && a != "T") {
			cout << "Nhap sai cu phap, moi nhap chuyen lai (N|I|X|T): ";
			cin >> a;
		}
		if (a == "N") {
			b.input();
		}
		else if (a == "I") {
			b.output();
		}
		else if (a == "X") {
			b.remove();
		}
		else if (a == "T") {
			cout << "Ket thuc chuong trinh";
			break;
		}
		cout << "Ban muon nhap, in, xoa, thoat (N|I|X|T): ";
		cin >> a;

	}
}