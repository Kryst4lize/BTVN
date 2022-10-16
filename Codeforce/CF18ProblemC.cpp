/*C. Menorah
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
#include<fstream>
//closest pair geeksforgeek
using namespace std;
ifstream inp("D:/input.txt");
ofstream out("D:/output.txt",ios::out);
// the location of point in OXY 
struct point {
	int x, y;
};
// get the distance between two point
long long distance(point a, point b) {
	return pow(abs(b.x) - abs(a.x), 2) + pow(abs(a.y) - abs(b.y), 2);
}
// find the min distance in an area
long long mindistanceX(vector<point>& check, int a, int b) {
	long long g = LLONG_MAX;
	for (int i = a; i < b; i++) {
		//check wether the min distance exceed the radius
		for (int j = i + 1; j < b && pow(check[j].x - check[i].x, 2) < g; j++) { 
			if (distance(check[i], check[j]) < g) {
				g = distance(check[i], check[j]); //middle on the right side
			}
		}
	}
	return g;
}
// This is an O(n) method, not O(n^2) because
// the inner loop can only run at most 6 times (was proven)
double mindistanceY(vector<point>& strip,double min) {
	for (int i = 0; i < strip.size(); i++) {
		for (int j = i + 1; j < strip.size() && double(strip[j].y) - double(strip[i].y) < min; j++) {
			if (sqrt(distance(strip[i], strip[j])) < min) {
				min = sqrt(distance(strip[i], strip[j]));
			}
		}
	}
	return min;
}
double bruteforceX(vector<point>&check) {
	double R = FLT_MAX;
	for (int i=0;i<check.size();i++){
		if (i == check.size() - 1) {
			if (sqrt(distance(check[i], check[0])) < R) {
				R = sqrt(distance(check[i], check[0]));
			}
		}
		else {
			if (sqrt(distance(check[i], check[i + 1])) < R) {
				R = sqrt(distance(check[i], check[i + 1]));
			}
		}
	}
	return R;
}

int maincf18() {
	double a;
	scanf_s("%lf", &a);
	printf("the first one is %lf", a); 
	int n = 2;
	inp >> n;
	while (n != 0) {
		vector<point>check(n);
		for (int i = 0; i < n; i++) {
			inp >> check[i].x;
			inp >> check[i].y;
		}
		// if element less than 3 ,using bruteforce more quickly
		if (n<=3 && n>=2){
			double d = bruteforceX(check);
			out << setprecision(9) << fixed << d << endl;
		}
		else if (n == 1) {
			out << -1 << endl;
		}
		else {
			//sort by x cordinate to divide into two part
			//Time complexity : O(nlog(n))
			sort(check.begin(), check.end(), [](point a, point b) {return a.x < b.x; });
			int mid = n / 2;
			//using bruteforce (recursive) with condition to find min distance in two side
			//Time complexity : approximately nearly linear 0(n) 
			long long minl = mindistanceX(check, 0, mid);
			long long minr = mindistanceX(check, mid, n);
			//get the min distance between two side
			double min2side = sqrt(min(minl, minr));
			//find every element in a strip length 2*min2side
			vector<point>strip;
			// reserve at least n element memory is stack memory in case you need
			strip.reserve(n);
			//get an array of element in the area of strip
			for (int i = 0; i < n; i++) {
				if (abs(check[i].x - check[mid].x) < min2side) {
					strip.push_back(check[i]);
				}
			}
			//sort array in y cordinate
			sort(strip.begin(), strip.end(), [](point a, point b) {return a.y < b.y; });
			double d = mindistanceY(strip, min2side);
			//the precision 10^-9
			out << setprecision(9) << fixed << d << endl;
		}
		inp >> n;
	}
	return 0;
}