/*Tanya is learning how to add numbers, but so far she is not doing it correctly. She is adding two numbers a and b using the following algorithm:

If one of the numbers is shorter than the other, Tanya adds leading zeros so that the numbers are the same length.
The numbers are processed from right to left (that is, from the least significant digits to the most significant).
In the first step, she adds the last digit of a to the last digit of b and writes their sum in the answer.
At each next step, she performs the same operation on each pair of digits in the same place and writes the result to the left side of the answer.
For example, the numbers a=17236 and b=3465 Tanya adds up as follows:

   17236
+  03465
=1106911
calculates the sum of 6+5=11 and writes 11 in the answer.
calculates the sum of 3+6=9 and writes the result to the left side of the answer to get 911.
calculates the sum of 2+4=6 and writes the result to the left side of the answer to get 6911.
calculates the sum of 7+3=10, and writes the result to the left side of the answer to get 106911.
calculates the sum of 1+0=1 and writes the result to the left side of the answer and get 1106911.
As a result, she gets 1106911.

You are given two positive integers a and s. Find the number b such that by adding a and b as described above, Tanya will get s. Or determine that no suitable b exists.

Input
The first line of input data contains an integer t (1≤t≤104) — the number of test cases.

Each test case consists of a single line containing two positive integers a and s (1≤a<s≤1018) separated by a space.

Output
For each test case print the answer on a separate line.

If the solution exists, print a single positive integer b. The answer must be written without leading zeros. If multiple answers exist, print any of them.

If no suitable number b exists, output -1.

Example
inputCopy
6
17236 1106911
1 5
108 112
12345 1023412
1 11
1 20
outputCopy
3465
4
-1
90007
10
-1*/
#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<climits>
#include<sstream>
#include<bitset>
using namespace std;
int main762B() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long a[101]; //minus one
	long long b[101];//result one
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; i++) {
		string count ;
		int check = 0;
		while (a[i] != 0 || b[i]!=0) {
			int flag1 = a[i] % 10;
			int flag2 = b[i] % 10;
			if (flag2 < flag1 ) {
				flag2 = b[i] % 100;
				if (flag2 < flag1 || flag2-flag1>9) { 
					cout << "-1" << endl; 
					check = 1; 
					break; 
				}
				else {
					count += char(flag2 - flag1+48);
					a[i] /= 10;
					b[i] /= 100;
				}
			}
			else {
				count +=char(flag2 - flag1+48);
				a[i] /= 10;
				b[i] /= 10;
			}
		}
		if (check == 0) {
			reverse(count.begin(), count.end());
			stringstream ss;
			ss << count;
			long long bruh;
			ss >> bruh;
			cout << bruh<<endl;
		}
		cout << endl;
	}
	return 0;
}