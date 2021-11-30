#include<stack>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
string reverse(string b){
	string k = "";
	for (int i = b.size() - 1; i > -1; i--) {
		k = k + b[i];
	}
	return k;
}
string repeat(int a,string b) {
	string k="";
	k = reverse(b);
	string d;
	for (int j = 0; j < a; j++) {
		d = d + k;
	}
	return d;
}
void decode(stack<char>&test) {
	//get word in []
		//remove ]
	test.pop();
	string word="";
	while (test.top() != '[') {
		word = word + test.top();
		test.pop();
	}
	//get number of time
		//remove [
	test.pop();
	int number = 0, base = 1;
	while (!test.empty() && test.top() >= '0' && test.top() <= '9') {
		number = number + ((test.top() - '0') * base);
		base *= 10;
		test.pop();
	}
	//return decode word
	word = repeat(number, word);
	for (int i = 0; i < word.size(); i++) {
		test.push(word[i]);
	}
}
string decodeString(string s){
	stack<char>test;
	for (int i = 0; i < s.size(); i++) {
		test.push(s[i]);
		if (test.top() == ']') {
			decode(test);
		}
	}
	string a;
	while (test.empty() == false) {
		a = a+ test.top();
		test.pop();
	}
	return reverse(a);
}
