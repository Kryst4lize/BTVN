#include<stack>
#include<iostream>
#include<math.h>
#include<string>
#include<sstream>
using namespace std;
string reversal(string a) {
	string b = "";
	for (int i = a.size() - 1; i > -1; i--) {
		b = b + a[i];
	}
	return b;
}
string repeat(int a, string b) {
	string c = "";
	for (int i = a; i != 0; i--) {
		c = c + b;
	}
	return c;
}
//decode from inside
void decode(stack<char>& test) {
	//get string inside and multiple it
	test.pop();
	string c;
	while (test.top() != '[') {
		c = c + test.top();
		test.pop();
	}
	//remove '['
	test.pop();
	//multiple string
		//convert char type to number 
	int a = 0, base = 1;
	while (test.top() <= '9' && test.top() >= '0' && test.empty() == false) {
		a = a + ((test.top() - '0') * base);
		base = base * 10;
		test.pop();
	}
	string b;
	stringstream s;
	s << a;
	s >> b;
	s << reversal(b);
	s >> a;
	a = 2;
	c = repeat(a, reversal(c));
	//return decode to stack 
	for (int i = 0; i < c.size(); i++) {
		test.push(c[i]);
	}
}
string decodeString(string s) {
	stack<char>test;
	string::iterator k;
	string final;
	for (k = s.begin(); k != s.end(); k++) {
		if (test.size() < 1) {
			test.push(*k);
		}
		else {
			test.push(*k);
			if (test.top() == ']') {
				decode(test);
			}
		}
	}
	while (test.empty() == false) {
		final.push_back(test.top());
		test.pop();
	}
	return reversal(final);
}
int mainm() {
	cout << decodeString("5[ab]");
	return 0;
}