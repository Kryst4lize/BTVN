#include<vector>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<climits>
#include<sstream>
#include<bitset>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int mainte1() {
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int b;
		string a;
		int check = 0;
		cin >> b >> a;
		if (b == 1) { cout << a + a; }
		else {
			string temps;
			for (int i = 0; i < a.length(); i++) {
				if (check == 1) { check = 0; break; }
				string fucker;
				for (int j = 0; j <= i; j++) {
					fucker += a[j];
				}
				for (int j = i; j >= 0; j--) {
					fucker += a[j];
				}
				if (temps.size() == 0) {
					temps = fucker;
				}
				else {
					for (int i = 0; i < temps.size(); i++) {
						if (fucker.size() == 2 * a.length()) { cout << fucker; check = 1; break; }
						if (fucker[i] < temps[i]) {
							temps = fucker;
							break;
						}
						else if (fucker[i] > temps[i]) {
							cout << temps << endl;
							check = 1;
							break;
						}
						else if (fucker[i] == temps[i]) {
							if (i == temps.size() - 1) {
								cout << temps << endl;
								check = 1;
								break;
							}

						}
					}
				}
			}
		}
	}
	return 0;
}