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
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int m;
        int check=0;
        cin>>m;
        string s;
        vector<int>arr(m);
        vector<int>arr2(m);
        for (int i=0;i<m;i++) {
            cin >> arr[i];
        }
        for (int i=0;i<m;i++){
            if (i == 0) {
                if (arr[i]<0){
                    s="-1";
                    break;
                }
                arr2[0] = arr[i];
                s += to_string(arr[i]);
                s += " ";
            } else {
                if (arr2[i - 1] - arr[i] >= 0) {
                    if (arr[i] != 0) {
                        s = "-1";
                        break;
                    } else {
                        arr2[i] = arr2[i - 1] + arr[i];
                        s += to_string(arr2[i]);
                        s += " ";
                    }
                } else {
                    arr2[i] = arr2[i - 1] + arr[i];
                    s += to_string(arr2[i]);
                    s += " ";
                }
            }
        }
        cout << s << endl;

    }
    return 0;
}
