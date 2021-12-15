#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int mainte1() {
	//input
	int g = 0;
	int max1=0; int maxinmin=0;
	int indexmax=0, indexmaxinmin=0;
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> g;
	for (int i = 0; i < g; i++) {
		int n, a, b;
		cin >> n >> a >> b;
		vector<int>map1(b);
		vector<int>check(b);
		for (int j = 0; j < b; j++) {
			map1[j] = j + 1;
		}
		//solve
		//get index
		int c = max(a, b);
		if (c < 2) {
			if (n < 3) {
				cout << "-1" << endl; continue;
			}
		}
		if (c >= 2) {
			if (3 + 2 * (c - 1) > n) { cout << "-1" << endl; continue; }
		}
		


	}
	return 0;
}