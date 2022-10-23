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
#include<map>
#include<utility>
using namespace std;
int main() {
    int k, n;
    cin >> n >> k;
    string s;
    cin >> s;
    int end = n - 1, start = 0;
    int quyen = 0, thang = 0, turn = 0;
    while (quyen < k && thang < k && start < end) {
        int check = 0;
        if (s[start] == 'B' && s[end] == 'B') {
            check = 1;
            if (s[start + 1] == 'B' && s[end - 1] == 'B') {
                cout << start << " ";
                start++;
            } else if (s[start + 1] == 'W') {
                cout << end << " ";
                end--;
            } else {
                cout << start << " ";
                start++;
            }
        } else {
            check = 0;
            if (s[start] == 'W') {
                cout << start << " ";
                start++;
            } else {
                cout << end << " ";
                end--;
            }
        }
        if (check) {
            if (turn % 2 == 0) {
                quyen++;
            } else {
                thang++;
            }
        }
        turn++;
    }
    cout << endl;
    if (thang > quyen) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
