#include<stack>
#include<iostream>
#include<vector>
using namespace std;
void sort(stack<int>& test,int &number) {
	while (test.size() >= 2) {
		int c = test.top();
		test.pop();
		if (c >= test.top() && test.size() > 0) {
			test.pop();
			test.push(c);
			number++;
			sort(test, number);
		}
		test.push(c);
	}
}
vector<int> removeElements(vector<int> arr, int k) {
	stack<int>final;
	int number = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (final.size() < 2) {
			final.push(arr[i]);
		}
		else {
			if (number < k) {
				sort(final, number);
				final.push(arr[i]);
			}
			else {
				final.push(arr[i]);
			}
		}

	}
	vector<int>b;
	while (final.empty()==false){
		b.push_back(final.top());
		final.pop();
	}
	reverse(b.begin(), b.end());
	return b;
}