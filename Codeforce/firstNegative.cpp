#include<vector>
#include<queue>
#include<iostream>
#include<math.h>
using namespace std;
vector<int> firstNegative(vector<int> a, int k) {
	vector<int>final;
	//spot the element of negative value
	for (int i = 0; i <= a.size() - k; i++) {
		for (int j = i; j <= i + k - 1; j++) {
			if (a[j] < 0) {
				final.push_back(a[j]);
				break;
			}
			if (j == i + k - 1) {
				final.push_back(0);
			}
		}
	}
	return final;
}