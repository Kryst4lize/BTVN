#include<utility>
#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<sstream>
using namespace std;
vector<int> mergeProducts(vector<string> A, vector<string> B) {
    map<string, bool>testcase;
    vector<int>a;
    for (string a : A) {
        testcase[a] = 1;
    }
    for (string b : B) {
        testcase.insert(make_pair(b, 0));
        if (testcase[b] == 0) {
            testcase[b]++;
            a.push_back(1);
        }
        else {
            if (testcase[b] == 1) {
                a.push_back(0);
            }
        }
    }
    return a;
}