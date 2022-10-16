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
    int a1;
    cin >> a1;
    for (int i = 0; i < a1; i++) {
        string a;
        cin >> a;
        vector<pair<int, int>> test;
        test.resize(a.length());
        for (int i = 0; i < a.length(); i++) {
            test[i].first = a[i] - 'a' + 1;
            test[i].second = i + 1;
        }
        std::sort(test.begin(), test.end());
        /* TODO:testing
        for (int i = 0; i < test.size(); i++) {
            cout<<test[i].first<<" "<<test[i].second<<endl;
        }*/
        int flag = 0;
        for (int i = 0; i < test.size(); i++) {
            if (test[i].second == 1) {
                flag = i;
                break;
            }
        }
        int flag1 = flag;
        for (int i = flag; i < test.size(); i++) {
            if (test[flag].first == test[i].first) {
                flag1 = i;
            } else {
                break;
            }
        }
        int start = flag1 + 1;
        int end = test.size() - flag;
        if (flag != 0) {
            //Get same value member of index 1
            if (start >= end) {
                cout << test[flag].first - test[0].first << " " << start << endl;
                for (int i = flag; i <= flag1; i++) {
                    cout << test[i].second << " ";
                }
                for (int i = flag - 1; i >= 0; i--) {
                    cout << test[i].second << " ";
                }
            } else {
                cout << test[test.size()-1].first - test[flag].first << " " << end << endl;
                for (int i = flag; i < test.size(); i++) {
                    cout << test[i].second << " ";
                }
            }
        } else {
            cout << test[test.size() - 1].first - test[0].first << " " << test.size() << endl;
            for (int i = 0; i < test.size(); i++) {
                cout << test[i].second << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
