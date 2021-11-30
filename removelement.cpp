#include<stack>
#include<iostream>
#include<vector>
using namespace std;
void sortnumber(stack<int>& test, int& number,int k) {
	if (test.size()>1 && number<k) {
		int c = test.top();
		test.pop();
		if (c >= test.top()) {
			number = number + 1;
			test.pop();
			test.push(c);
			sortnumber(test, number, k);
		}
		if (c < test.top()) {
			test.push(c);
		}
	}
}
vector<int> removeElements(vector<int> arr, int k){
	int number = 0;
	stack<int>test;
	for (int i = 0; i < arr.size(); i++) {
		if (number >= k) {
			test.push(arr[i]);
		}
		else {
			if (test.size() < 1) {
				test.push(arr[i]);
			}
			else {
				test.push(arr[i]);
				sortnumber(test, number,k);
			}
		}
	}
	vector<int> final;
	while (test.empty() == false) {
		final.push_back(test.top());
		test.pop();
	}
	reverse(final.begin(), final.end());
	return final;
}
