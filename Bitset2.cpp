#include<iostream>
#include<bitset>
#include<vector>
#include<string>
using namespace std;
vector<int> checkActivity(int n) {
	bitset<30>foo(n);
	vector<int>final;
	for (int i = 0, k = 0; i < foo.count();) {
		if (foo[k]) {
			i++;
			final.push_back(1);
			k++;
		}
		else {
			k++;
			final.push_back(0);
		}
	}
	return final;
}
char convertChar(char ch){
	bitset<7>foo(ch);
	foo.flip();
	char c = foo.to_ullong();
	return c;
}