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
int GDC(int a,int b){

}
int main() {
    int a1;
    cin >> a1;
    cin.ignore();
    for (int i = 0; i < a1; i++) {
        int n,q;
        cin>>n>>q;
        vector<int>step(n);
        vector<int>leg(q);
        for (int i=0;i<n;i++){
            cin>>step[i];
        }
        for (int i=0;i<q;i++){
            cin>>leg[i];
        }
        vector<pair<int,long long>>array(1);
        array[0].first=step[0];
        array[0].second=step[0];
        for (int i=1;i<n;i++){
            if (step[i]>array[array.size()-1].first){
                array.push_back(pair(step[i],array[array.size()-1].second+step[i]));
            } else {
                array[array.size()-1].second+=step[i];
            }
        }
        for (int i=0;i<array.size();i++){
            // cout<<array[i].first<<" "<<array[i].second<<endl;
        }

        // binary search
        vector<long long>res(leg.size());
        for (int i=0;i<leg.size();i++) {
            int start = 0, last = array.size() - 1;
            int mid;
            while (start <= last) {
                // cout<<"Start la: "<<start<<",Last la: "<<last<<endl;
                mid=(start +last)/2;
                if (leg[i]>=array[mid].first){
                    res[i]=array[mid].second;
                    start=mid+1;
                } else {
                    last=mid-1;
                }

            }
            // cout<<"Khi ket thuc step la: "<<step[i]<<", Start la: "<<start<<",Last la: "<<last<<", mid la: "<<mid<<", gia tri tim duoc la "<<res[i]<<endl;
        }
        for (auto a:res){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}
