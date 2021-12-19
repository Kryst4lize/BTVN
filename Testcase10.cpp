#include <iostream>
using namespace std;
#include<string>
#include<sstream>
#include<iomanip>
long double shrimp(double n) {
	long double  x = 0;
    long double  flag1 = n;
	unsigned long long flag2 = 1;
	unsigned long long flag3 = 1;
	for (int i = 0 ; i < 28; i++) {
		if (flag3 % 2 == 1) {
			if ((flag3/2) % 2 == 0) {
				x += flag1 / (long double)flag2;
				flag1 *= n;
				flag3++;
				flag2 *= (flag3);
			}
			else {
				x -= flag1 / (long double)flag2;
				flag1 *= n;
				flag3++;
				flag2 *= (flag3);
			}
		}
		else {
			flag3++;
			flag1 *= n;
			flag2 *= (flag3);
		}
	}
	return x;
}
int mainte10() {
	double n;
	cin >> n;
	cout << setprecision(4)<<fixed<< shrimp(n);
	return 0;
}
