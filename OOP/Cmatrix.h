#pragma once
/*
class Cvector
{
private:
	vector<int>arr;
public:
	Cvector() {
		setVector();
	};
	Cvector(int data, vector<int>arr2) {
		arr.resize(data);
		for (int i = 0; i < data; i++) {
			arr[i] = arr2[i];
		}
	}
	int getSize() {
		return arr.size();
	}
	int getElement(int i) {
		return arr[i];
	}
	void setVector() {
		int n = 0;
		cout << "Moi nhap so phan tu: ";
		cin >> n;
		while (n < 0) {
			cout << "So phan tu khong hop le, vui long nhap lai: ";
			cin >> n;
		}
		arr.resize(n);
		cout << "Moi nhap " << n << " gia tri cua vector";
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
	}
	void print() {
		cout << "Gia tri cua cac phan tu trong vector da chieu la: " << endl;
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	const Cvector operator +(Cvector a) {
		if (this->getSize() != a.getSize()) {
			cout << "Hai vector nay khong cung kich thuoc, nen khong cong dc";
		}
		else {
			for (int i = 0; i < this->getSize(); i++) {
				arr[i] += a.getElement(i);
			}
		}
		return (*this);
	}
	const Cvector operator -(Cvector a) {
		if (this->getSize() != a.getSize()) {
			cout << "Hai vector nay khong cung kich thuoc, nen khong tru dc";
		}
		else {
			for (int i = 0; i < this->getSize(); i++) {
				arr[i] -= a.getElement(i);
			}
		}
		return (*this);
	}
	const int operator *(Cvector a) {
		int index = 0;
		if (this->getSize() != a.getSize()) {
			cout << "Hai vector nay khong cung kich thuoc, nen khong tru dc";
		}
		else {
			for (int i = 0; i < this->getSize(); i++) {
				index += (arr[i] * a.getElement(i));
			}
		}
		return index;
	}
};
*/
