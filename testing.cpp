#include"Bai2.h"
#include"Bai5.h"
#include"Week2.h"
// you can use includes, for example:
#include <algorithm>
#include<map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    return 0;
    map<int, int>arr;
    for (auto a : A) {
        arr[a]++;
    }
    for (auto b : arr) {
        cout << b.first << " " << b.second;
    }
    // write your code in C++14 (g++ 6.2.0)
}
int main() {
    Checking2("output.txt");
}