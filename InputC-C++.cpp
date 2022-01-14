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
#include<string.h>
#include <stdio.h>
#include<cstring>
using namespace std;
#define ll long long
ll divide=1000000007;
vector<long long >check(3);
int CeilIndex(vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength(vector<int>& v)
{
    if (v.size() == 0)
        return 0;
    std::vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
    return length;
}

int mainC()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << LongestIncreasingSubsequenceLength(v) << '\n';
    return 0;
}