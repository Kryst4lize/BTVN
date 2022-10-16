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
#include<cstring>
#include<sstream>
#include<tuple>
#include<fstream>
using namespace std::chrono;
using namespace std;
int mainarsuff() {
	string s;
	cin >> s;
	int idx = s.length();
	s += '$';
	int n=idx+1;
	vector<int>p(n), c(n); //p to store the right index, c to store the increment order
	{
		vector<pair<char, int>>index(s.length());
		for (int i = 0; i < s.length(); i++) {
			index[i] = { s[i],i };
		}
		sort(index.begin(), index.end());
		// initialize first sort chracter index
		for (int i = 0; i < s.length(); i++) {
			p[i] = index[i].second;
		}
		// initial the order to compare 
		c[p[0]] = 0;
		for (int i = 1; i < s.length() ; i++) {
			if (index[i].first == index[i - 1].first) {
				c[p[i]] = c[p[i-1]]; //if character is same, dont increase the order
			}
			else {
				c[p[i]] = c[p[i-1]] + 1; // if character is not the same, increase the sequence order
			}
		}/*
		for (int i = 0; i < n; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << c[i] << " ";
		}*/
		cout << endl;
		//make transition
		int k = 0;
		while ((1<<k) < n) {
			vector<pair<pair<int, int>, int>>arr(n);
			//first variable is a pair contain two array need to compare, the second one to count the current index
			for (int i = 0; i < n; i++) {
				arr[i] = { {c[i],c[(i + (1 << k)) % n]},i }; //modulus idx due to the cycling 
			}
			sort(arr.begin(), arr.end()); //sort to c[i].first.first, then c[i].first.second
			/*for (auto a : arr) {
				cout << a.first.first << " " << a.first.second << endl;
			}*/
			for (int i = 0; i < n; i++) {
				p[i] = arr[i].second;
			}
			c[p[0]] = 0; // reset new order
			for (int i = 1; i < n; i++) {
				if (arr[i].first == arr[i - 1].first) {
					c[p[i]] = c[p[i - 1]];
				}
				else {
					c[p[i]] = c[p[i - 1]] + 1;
				}
			}
			k++;
		}
		for (auto a : p) {
			if (a <=idx){
				cout << a << " "; 
				//cout << s.substr(a, idx - a) << endl;
			}
		}
	}
	return 0;
}