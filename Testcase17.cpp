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
int mainte17() {
	int m;
	cin >> m;
	//O(m)
	for (int i = 0; i < m; i++) {
		long long inp, n;
		cin >> n;
		int sum = 0;
		vector<long long> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int flag1 = 0; //(check same)
		vector<long long> comp(n - 1);
		for (int i = 0; i < n - 1; i++) {
			comp[i] = arr[i + 1] - arr[i];
			if (comp[i] == 0) {
				flag1++;
			}
		}
		if (n <= 2 || flag1 == 1) {
			cout << 0 << endl;
		}
		else {
			int res = 0, count = 0;
			for (int i = 0; i < n - 1; i++) {
				if (comp[i] == 0) { count++; }
				else {//2  1 1 1 1 1 1 1 1 3 3
					if (count <= 0) {}
					else if (count % 2 == 1) {
						res += (count / 2 + 1);
						count = 0;
					}
					else {
						res += count / 2;
						count = 0;
					}
				}
			}
			if (count % 2 == 1) {
				res += (count / 2 + 1);
			}
			else {
				res += count / 2;
			}
			cout << res << endl;
		}
	}
	//O(m*nlogn)
	return 0;
}