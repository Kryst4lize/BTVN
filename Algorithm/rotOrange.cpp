#include<vector>
#include<iostream>
using namespace std;
/**to check adjacent element is still in the matrix
 (some corner or lines do not have 4 adjacent element nearby) */
bool checklegit(vector<vector<int>>a, int x, int y) {
	if (x < a.size() && x>-1 && y > -1 && y < a[x].size()) {
		return true;
	}
	else { return false; }
}
void checkBoundary1(vector<vector<int>>&a, int x, int y, int& count) {
	//increase the value of new rotten apple to value 3 in order to avoid the new infection 
	// if value of new rotten apple is 2, in the next check of element, it could be infected
	if (checklegit(a, x + 1, y)==true && a[x + 1][y] == 1) {
		a[x + 1][y]= 3;
		count--;
	}
	if (checklegit(a, x - 1, y)==true && a[x - 1][y] == 1) {
		a[x - 1][y]= 3;
		count--;
	}
	if (checklegit(a, x, y + 1)==true && a[x][y + 1] == 1) {
		a[x][y + 1]= 3;
		count--;
	}
	if (checklegit(a, x, y - 1)==true && a[x][y - 1] == 1) {
		a[x][y - 1]= 3;
		count--;
	}
}
int rotOrange(vector<vector<int>>& matrix){
	int count = 0, stage = 0;
	//count the intact apple
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0 || matrix[i][j] == 2) {
				continue;
			}
			if (matrix[i][j] == 1) {
				count++;
			}
		}
	}
	int after = -1;
	//start count the phase when the apple rotten
	while (count != 0 && after != count) {
		after = count;
		//search the rotten apple and infect adjacent intact apple
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				//reduce the time to search infect apple
				if (matrix[i][j] == 0 || matrix[i][j] == 1 || matrix[i][j]==3) {
					continue;
				}
				//infect stage
				if (matrix[i][j] == 2) {
					checkBoundary1(matrix, i, j, count);
				}
			}
		}
		stage++;
		//refresh the new rotten apple (value 3 in matrix) by minus 1
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] == 3) {
					matrix[i][j] = 2;
				}
			}
		}
	} 
	if (count <= 0) { return stage; }
	if (count > 0) { return -1; }	
}
