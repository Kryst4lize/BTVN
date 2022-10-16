#include<string>
#include<sstream>
#include<vector>
#include<list>
#include<set>
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
using namespace std;
long long GDC(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return GDC(b, a % b);
	}	 
}
int mainpresuf() {
	//input
	long long n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector <long long> similar(n - 1);
	for (int i = 0; i < n - 1; i++) {
		similar[i] = GDC(arr[i], arr[i + 1]);
	}
	vector<long long >prefix(n - 1, 0);
	prefix[0] = arr[0];
	//figure engineering
	for (long long i = 1; i < n - 1; i++) {
		prefix[i] = min(prefix[i - 1], similar[i]);
	}
	vector<long long>suffix(n - 1);
	suffix[n - 2] = similar[n - 2];
	for (long long i = n - 3; i > -1; i--) {
		suffix[i] = min(suffix[i + 1], similar[i]);
	}
	//finish
	long long index = 1;
	long long ans = suffix[0];
	if (n < 4) {
		long long temp1 = GDC(arr[0],arr[1]);
		long long temp2 = GDC(arr[1], arr[2]);
		long long temp3 = GDC(arr[2], arr[0]);
		if (temp1 > ans) {
			ans = temp1;
			index = 3;
		}
		if (temp2 > ans) {
			ans = temp2;
			index = 1;
		}
		if (temp3 > ans) {
			ans = temp3;
			index = 2;
		}
	}
	else {
		for (long long i = 0; i < n; i++) {
			if (i == 0 || i == n - 1) {
				int temp;
				if (i == 0) {
					temp = suffix[i + 1];
				}
				else {
					temp = prefix[i - 2];
				}
				if (temp > ans) {
					ans = temp;
					index = i + 1;
				}
				//cout << ans << " ";
			}
			else if (i == 1 || i == n - 2) {
				int temp;
				if (i == 1) {
					temp = GDC(arr[i - 1], suffix[i + 1]);
				}
				else {
					temp = GDC(arr[i + 1], prefix[i - 2]);
				}
				if (temp > ans) {
					ans = temp;
					index = i + 1;
				}
				//cout << ans << " ";
			} // 0 1 2 3 4
			 // 0 1 2 4
			else {
				int temp = max(ans, GDC(suffix[i + 1], prefix[i - 2]));
				if (temp > ans) {
					ans = temp;
					index = i + 1;
				}
				//cout << ans << " ";
			}
		}
	}
	cout << index << " " << ans;
	return 0;
}