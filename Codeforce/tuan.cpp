//
// Created by Administrator on 3/26/2023.
//
#include<stack>
#include<iostream>
#include<vector>
#define MOD 10000
using namespace std;

int sumOfMinSubarray(vector<int>&num){
    stack<int>index;
    vector<int>right(num.size()+1);
    vector<int>dp(num.size()+1);
    int arr[num.size()+1];
    int n=num.size();
    arr[0]=-MOD;
    dp[0]=0;
    for (int i=0;i<n;i++){
        right[i]=i;
        arr[i+1]=num[i];
    }
    for (int i=0;i<n+1;i++){
        int cnt=i;
        while (!index.empty() && (arr[i]<=arr[index.top()])){
            cnt=index.top();
            index.pop();
        }
        right[i]=cnt;
        if (index.empty()){
            index.push(0);
        }
        index.push(i);
    }
    for (int i=0;i<n+1;i++){
        cout<<right[i]<<" ";
    }
    cout<<endl;
    for (int i=1;i<n+1;i++){
        if (right[i]==i){
            dp[i]=(dp[i-1]+arr[i])%MOD;
        }
        else {
            dp[i]=(dp[right[i]]+(i-right[i])*arr[i])%MOD;
        }
    }
    for (int i=0;i<n+1;i++){
        cout<<dp[i]<<"  ";
    }
    cout<<endl;
    int sum=0;
    for (int i=0;i<n+1;i++){
        sum+=dp[i];
        sum%=MOD;
    }
    return sum;
}
int main(){
    vector<int>a;
    int n;
    cin>>n;
    a.resize(n);
    stack<int>index;
    vector<int>right(n);
    vector<int>dp(n);
    //TODO: INPUT array
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    //TODO: initialize higher right array's value
    for (int i=0;i<n;i++){
        right[i]=i;
    }

    //TODO: setting index range of higher value
    int cnt=0;
    for (int i=0;i<n;i++){
        cnt=i;
        while (!index.empty() && (a[i]<=a[index.top()])){
            cnt=index.top();
            index.pop();
        }
        right[i]=cnt;
        index.push(i);

    }
    cout<<"Done1"<<endl;
    for (int i=0;i<n;i++){
        cout<<right[i]<<" ";
    }
    cout<<endl;


    //TODO: calculate dp dynamic programming
    dp[0]=a[0];
    for (int i=1;i<n;i++){
        if (right[i]==i){
            dp[i]=dp[i-1]+a[i];
        }
        else {
            dp[i]=dp[right[i]]+(i-right[i])*a[i];
        }
    }
    /*cout<<"Done2"<<endl;
    for (int i=0;i<n;i++){
        cout<<dp[i]<<"  ";
    }
    cout<<endl;*/
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=dp[i];
    }
    cout<<sum<<endl<< sumOfMinSubarray(a);
    return 0;
}