#include<sstream>
#include<stack>
#include<iostream>
using namespace std;
int mainss() {
	stack<char>test;
	test.push('a');
	test.push('1');
	test.push(52);
	test.push('6');
	test.push('8');
	string number;
	while (test.top() >= '0' && test.top() <= '9' && test.empty()==false) {
		number.push_back(test.top());
		test.pop();
	}
	stringstream s;
	s << number;
	int a;
	s >> a;
	cout << a;
	return 0;
}


