#include<vector>
#include<iostream>
#include<string>
using namespace std;
bool res = 0;
void solve(string num, int idx, double a, double  b, bool found) //string; 0; -1; -1; false
{
    cout<<a<<" "<<b<<" "<<idx<<endl;
    if (idx == num.size())
    {
        if (found)
            res = 1;
        return;
    }
    string t;
    for (int i = idx; i < num.size(); ++i)
    {
        t += num[i];
        if (t.size() > 1 && t[0] == '0')
            return;
        double  p = stod(t);
        if (a == -1)
        {
            solve(num, i + 1, p, b, found);
        }
        else if (b == -1)
        {
            solve(num, i + 1, a, p, found);
        }
        else
        {
            //cout<<a<<" "<<b<<endl;
            if (p > a + b)
            {
                return;
            }
            else if (p == a + b)
            {
                //cout<<a<<" "<<b<<" "<<p<<endl;
                solve(num, i + 1, b, p, true);
            }

        }
        if (res == 1)
            return;
    }
}
bool isAdditiveNumber(string num) {
    int n = num.size();
    if (n == 1 || n == 2)
        return 0;
    solve(num, 0, -1, -1, false);
    return res;
}
int mainte7() {
    string a;
    cin >> a;
    if (isAdditiveNumber(a) == true) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}