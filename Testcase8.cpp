#include <iostream>
using namespace std;
#define MAX 100
void Nhapmang(int a[], int& n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
	bool isBenford(int a[], int& n) {

		int flag1 = 0, flag2 = 0;
		for (int i = 0; i < n; i++) {
			while (a[i] >= 10) {
				a[i] /= 10;
			}
			if (a[i] == 1) { flag1++; }
			if (a[i] == 4) { flag2++; }
		}
		if (flag1 >= 3 && flag2 >= 1) {
			return true;
		}
		else {
			return false;
		}
	}
	int main()
	{
		int a[MAX], n = 10;
		Nhapmang(a, n);
		if (isBenford(a, n) == true)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
		return 0;
	}