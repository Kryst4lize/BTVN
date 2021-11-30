#include<utility>
#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<sstream>
using namespace std;
vector<string> countChar(string s) {
	map<char, int>testcase;
	vector<string>final;
	int size = 0;
	for (int i = 0; i < s.length(); i++) {
		testcase.insert({ s[i], 0 });
		if (testcase.size() > size) {
			size++;
		}
		if (testcase.size() == size) {
			(testcase.find(s[i]))->second++;
		}
	}
	for (auto k = testcase.begin(); k != testcase.end(); k++) {
		stringstream l;
		l << k->second;

		string d;
		l >> d;
		string ans="";
		ans = ans + k->first + " " + d;
		final.push_back(ans);
	}
	return final;
}

