#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
void mincoin(vector<int>& coin, int number, int price, int& abs, int index) {
	if (abs < number) { return; }
	if (abs!=INT_MAX && abs * coin[index] < price) { return; }
	for (int j = index; j < coin.size(); j++) {
		if (price - coin[j] > 0) {
			mincoin(coin, number + 1, price - coin[j], abs, j);
		}
		if (price - coin[j] == 0) {
			if (abs > number) { abs = number; }
			return;
		}
	}
}
int maingr1() {
	int abs = INT_MAX;
	int n = 0;
	int s=0;
	cin >> n >> s;
	vector<int>coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin.rbegin(), coin.rend());
	for (int i = 0; i < coin.size(); i++) {
		mincoin(coin, 1, s, abs, i);
	}
	cout <<endl<<abs;
	//input
	return 0;

}