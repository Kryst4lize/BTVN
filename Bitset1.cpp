#include<iostream>
#include<bitset>
#include<string>
using namespace std;
int countOperations(int n) {
	bitset<30>foo(n);
	return foo.count();
}
