﻿/*C. Menorah
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n candles on a Hanukkah menorah, and some of its candles are initially lit. We can describe which candles are lit with a binary string s, where the i-th candle is lit if and only if si=1.


Initially, the candle lights are described by a string a. In an operation, you select a candle that is currently lit. By doing so, the candle you selected will remain lit, and every other candle will change (if it was lit, it will become unlit and if it was unlit, it will become lit).

You would like to make the candles look the same as string b. Your task is to determine if it is possible, and if it is, find the minimum number of operations required.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases. Then t cases follow.

The first line of each test case contains a single integer n (1≤n≤105) — the number of candles.

The second line contains a string a of length n consisting of symbols 0 and 1 — the initial pattern of lights.

The third line contains a string b of length n consisting of symbols 0 and 1 — the desired pattern of lights.

It is guaranteed that the sum of n does not exceed 105.

Output
For each test case, output the minimum number of operations required to transform a to b, or −1 if it's impossible.

Example
inputCopy
5
5
11010
11010
2
01
11
3
000
101
9
100010111
101101100
9
001011011
011010101
outputCopy
0
1
-1
3
4
Note
In the first test case, the two strings are already equal, so we don't have to perform any operations.

In the second test case, we can perform a single operation selecting the second candle to transform 01 into 11.

In the third test case, it's impossible to perform any operations because there are no lit candles to select.

In the fourth test case, we can perform the following operations to transform a into b:

Select the 7-th candle: 100010111→011101100.
Select the 2-nd candle: 011101100→110010011.
Select the 1-st candle: 110010011→101101100.
In the fifth test case, we can perform the following operations to transform a into b:

Select the 6-th candle: 001011011→110101100
Select the 2-nd candle: 110101100→011010011
Select the 8-th candle: 011010011→100101110
Select the 7-th candle: 100101110→011010101
*/
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
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long sum = 0;
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int answer;
			cin >> answer;
			sum += answer;
		}
		if (sum % a == 0) {
			cout << 0 << endl;
		}
		else { cout << 1 << endl; }
	}

	return 0;
}