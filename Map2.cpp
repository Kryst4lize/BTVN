#include<utility>
#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<sstream>
using namespace std;
vector<int> countPrefix(vector<string> contacts, vector<string> names)
{
    map<string, int> mp;
    for (auto s : names) {
        mp[s];
        for (auto strings:contacts) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i]!=strings[i]){
                    break;
                }
                mp[s]++;
            }
        }
    }
    vector<int> result;
    for (auto name : names) {
        result.push_back(mp[name]);
    }
    return result;
}

