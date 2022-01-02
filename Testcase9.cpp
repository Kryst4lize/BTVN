#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
void expand(vector<vector<char>> map, vector<vector<int>>mark, string sample, int indexstring, int x, int y, bool& check) {
	if (x > -1 && x<map.size() && y>-1 && y < map[0].size() && mark[x][y] == 0 &&indexstring<sample.size()) {
		if (map[x][y] == sample[indexstring]) {
			mark[x][y] = 1;
			if (indexstring >= sample.size() - 1) { check = 1; return; }
			expand(map, mark, sample, indexstring + 1, x + 1, y, check);
			if (check == 1) { return; }
			expand(map, mark, sample, indexstring + 1, x, y + 1, check);
			if (check == 1) { return; }
			expand(map, mark, sample, indexstring + 1, x - 1, y, check);
			if (check == 1) { return; }
			expand(map, mark, sample, indexstring + 1, x, y - 1, check);
			if (check == 1) { return; }
		}
	} 
}
string searchword(vector<vector<char>>map, string sample) {
	bool check = 0;
	//create marking direction vector
	vector<vector<int>>mark(map.size());
	for (int i = 0; i < map.size(); i++) {
		mark[i].resize(map[i].size(), 0);
	}
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			expand(map, mark, sample, 0, i, j, check);
			if (check == 1) { return "true"; }
		}
	}
	return "false";
}
int mainte9() {
	//[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
	//[['c', 'c', 'c', 'Z'], ['Z', 'c', 'Z', 'c'], ['c', 'c', 'c', 'Z'], ['c', 'Z', 'Z', 'c'], ['Z', 'c', 'Z', 'c']]
	string s,sample;
	getline(cin, s); 
	getline(cin, sample);
	int flag1 = 0; //take [
	int flag2 = 0; //take ,
	int flag3 = 0; //count the string 
	string input;
	for (auto a : s) {
		if (a == '[') {
			flag1++;
		}
		if (a == ',') {
			flag2++;
		}
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
			input += a;
		}
	}
	//calculate row and collumn and create map vector with that value
	int row = flag1 - 1;
	int column = ((flag2 - (flag1 - 2)) / (flag1 - 1)) + 1;
	vector<vector<char>>map(row);
	for (int i = 0; i < row; i++) {
		map[i].resize(column);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column;j++) {
			map[i][j] = input[flag3];
			flag3++;
		}
	}
	cout << endl<< searchword(map, sample);
	return 0;
}