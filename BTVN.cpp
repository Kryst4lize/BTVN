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
int main() {
		long long a,index=0;
		int even = 0, odd = 0, speceven = 0;
		long long b;
		cin >> a;
		if (a % 5 == 0) {
			cout << a / 5;
		}
		else {
			cout << a / 5 + 1;
		}
	return 0;
}