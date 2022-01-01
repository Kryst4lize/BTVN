#include<string>
#include<sstream>
#include<iomanip>
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
int summon[100] = { 0 };
int k,check;
vector<vector<int>>tree2;
void point(int sum, int a) {
	for (int j = 0; a < tree2.size() && j < tree2[a].size(); j++) {
		summon[a] = tree2[a][j];
		if (sum + tree2[a][j] < k ) {
			if (a < 1) {
				point(sum + tree2[a][j], a + 1);
			}
			else {
				if (tree2[a][j] >= summon[a - 1]) {
					point(sum + tree2[a][j], a + 1);
				}
			}
		}
		else {
			if (sum + tree2[a][j] == k && a == tree2.size() - 1) {
				check = 1;
				return;
			}
		}
		if (check == 0 || check == 1) { return; }
	}
}
			

		
	
int mainte10() {
	int s, n, m;
	cin >> s >> m >> n; //m bai thi, n giam khao, s diem
	k = s;
	/*230 10 4
20 20 30 42 50 70 71 80 90 100
15 20 27 40 42 26 60 79 22 20
10 18 20 20 21 20 20 20 20 18
5 6 9 11 20 8 15 16 12 10*/
//input
	vector<vector<int>>checks(n);
	for (int i = 0; i < n; i++) {
		checks[i].resize(m);
	}
	vector<vector<int>>tree(m);
	for (int i = 0; i < m; i++) {
		tree[i].resize(n);
	}
	//convert into another vector dimension
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> checks[i][j];
			tree[j][i] = checks[i][j];
		}
	}
	tree2 = tree;
	//solving
	check = 2;
	point(0, 0);
	if (check == 1) { cout << "YES"; }
	else { cout << "NO"; }
	cout << endl;
	return 0;
}