#include<string>
#include<sstream>
#include<vector>
#include<list>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<climits>
#include<bitset>
#include<fstream>
#include<chrono>
#include<functional>
#include<utility>
#include<limits>
#include<vector>
#include<random>
#include<sstream>
#include<tuple>
#include<fstream>
using namespace std::chrono;
using namespace std;

string InfixToPostfix(string input) {
	string res;
	stack<pair<int, string>>postfix;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {}
		//lowest priority
		else if (input[i] == '+' || input[i] == '-') {
			if (postfix.empty()) {
				postfix.push(make_pair(1, ""));
				postfix.top().second += input[i];
			}
			else if (postfix.top().first < 2) {
				postfix.push(make_pair(1, ""));
				postfix.top().second += input[i];
			}
			else {
				res = res + postfix.top().second + " ";
				postfix.pop();
				postfix.push(make_pair(1, ""));
				postfix.top().second += input[i];
			}
		}
		else if (input[i] == '/' || input[i] == '*') {
			if (postfix.empty()) {
				postfix.push(make_pair(2, ""));
				postfix.top().second += input[i];
			}
			// higher priority
			else if (postfix.top().first < 2) {
				postfix.push(make_pair(2, ""));
				postfix.top().second += input[i];
			}
			// same priority
			else {
				res = res + postfix.top().second + " ";
				postfix.pop();
				postfix.push(make_pair(2, ""));
				postfix.top().second += input[i];
			}
		}
		else if (input[i] >= '0' && input[i] <= '9') {
			postfix.push(make_pair(0, ""));
			while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
				postfix.top().second += input[i];
				i++;
			}
			i--;
			res = res + postfix.top().second + " ";
			postfix.pop();
		}
		else if (input[i] == '(') {
			postfix.push(make_pair(-1, ""));
			postfix.top().second += input[i];
		}
		else if (input[i] == ')') {
			while (postfix.top().second != "(") {
				res = res + postfix.top().second + " ";
				postfix.pop();
			}
			postfix.pop();
		}
	}
	while (!postfix.empty()) {
		res = res + postfix.top().second + " ";
		postfix.pop();
	}
	return res;
}
double calculatePostfix(string input) {
	stringstream ss;
	ss << input;
	string temp;
	stack<double>check;
	while (ss >> temp) {
		if (temp[0] >= '0' && temp[0] <= '9') {
			check.push(stoi(temp));
		}
		else {
			double a = check.top();
			check.pop();
			if (temp == "+") {
				check.top() = check.top() + a;
			}
			else if (temp == "-") {
				check.top() = check.top() - a;
			}
			else if (temp == "*") {
				check.top() = check.top() * a;
			}
			else if (temp == "/") {
				check.top()=check.top()/a;
			}
		}
	}
	double res = check.top();
	return res;
}
int mainpostExpression() {
	return 0;
}