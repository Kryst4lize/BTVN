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
int mainte5() {
	int n;
	cin >> n;
	double area = 0;
	vector<pair<double,double>>check(n);
	for (int i = 0; i < n; i++) {
		cin >> check[i].first >> check[i].second;
	}
	if (check[0].first < check[n - 1].first) {
		area -= 0.5 * (check[0].first * check[n - 1].second - check[n - 1].first * check[0].second);
	}
	else {
		area += 0.5 * (check[0].first * check[n - 1].second - check[n - 1].first * check[0].second);
	}
	for (int i = 0; i < n-1; i++) {
		if (check[i].first < check[i + 1].first) {
			area -= 0.5 * double(check[i].first * check[i + 1].second - check[i + 1].first * check[i].second);
		}
		else {
			area += 0.5 * double(check[i].first * check[i + 1].second - check[i + 1].first * check[i].second);
		}
	}
	cout << area;
	return 0;
}