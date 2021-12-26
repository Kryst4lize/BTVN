
/*A string is called square if it is some string written twice in a row. For example, the strings "aa", "abcabc", "abab" and "baabaa" are square. But the strings "aaa", "abaaab" and "abcdabc" are not square.

For a given string s determine if it is square.

Input
The first line of input data contains an integer t (1≤t≤100) —the number of test cases.

This is followed by t lines, each containing a description of one test case. The given strings consist only of lowercase Latin letters and have lengths between 1 and 100 inclusive.

Output
For each test case, output on a separate line:

YES if the string in the corresponding test case is square,
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).

Example
inputCopy
10
a
aa
aaa
aaaa
abab
abcabc
abacaba
xxyy
xyyx
xyxy
outputCopy
NO
YES
NO
YES
YES
YES
NO
NO
NO
YES*/
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;


int main762A() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a;
	cin >> a;
	vector<string>check(a);
	for (int i = 0; i < a; i++) {
		cin >> check[i];
	}
	for (int i = 0; i < a; i++) {
		if (check[i].size() % 2 == 1) { cout << "NO" << endl; }
		else {
			string flag1 = "", flag2 = "";
			int b = (check[i].size()) / 2;
			for (int j = 0; j < b; j++) {
				flag1 += check[i][j];
			}
			for (int j = b; j < check[i].size(); j++) {
				flag2 = flag2 + check[i][j];
			}
			if (flag1 == flag2) { cout << "YES" << endl; }
			else { cout << "NO" << endl; }
		}
	}
	return 0;
}