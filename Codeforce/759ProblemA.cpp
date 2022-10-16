#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main759 () {
	//input
	int input = 0;
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> input;
	for (int i = 0; i < input; i++) {
		int a = 0;
		cin >> a;
		vector<int>b(a);
		for (int j = 0; j < a; j++) {
			cin >> b[j];
		}
		//solve
		int count = 0;
		int max1 = *max_element(b.begin(), b.end());
		while (1) {
			int d = b.size() - 1;
			int count1 = 0;
			if (max1 == b[d]) { break; }
			vector<int>check;
			int count2 = 0;
			for (int k = 0; k < b.size(); k++) {
				if (b[k] > b[d]) {
					check.push_back(b[k]);
				}
			}
			b = check;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}