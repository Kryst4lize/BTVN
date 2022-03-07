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
#define ll long long 
using namespace std;
int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll res2;
	ll end = (long long)1e16, start = 0;
	while (start <= end) {
		ll res = (start + end) >> 1;
		//cout << start << " " << res << " " << end << endl;
		ll count = 0, i = 0;
		vector<ll>chapter(m);
		for (; i < n && count < m; i++) {
			if (chapter[count] == 0) {
				if (chapter[count] + arr[i] > res) {
					start = res;
					break;
				}
				else {
					chapter[count] += arr[i];
				}
			}
			else {
				if (chapter[count] + arr[i] > res) {
					count++;
					i--;
				}
				else {
					chapter[count] += arr[i];
				}
			}
		}
		/*for (auto a : chapter) {
				cout << a << " ";
			}
			cout << endl;*/
			//5 3

			//3 7 12 8 5
		if (i == n) {
			if (count > m - (long long)1) {
				start = res + (long long)1;
			}
			else {
				res2 = res;
				end = res - (long long)1;
			}
		}
		else {
			//can it so de hoanf thanh n chuong
			start = res + 1;
		}
	}
	cout << res2;
}