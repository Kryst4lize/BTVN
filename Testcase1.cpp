#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int n = 0, x = 0, a = 0, b = 0;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++) {
		x += (a * b);
		a++;
		b++;
	}
	cout << x;
	return 0;
}
