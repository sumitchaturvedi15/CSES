#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return 1e9;
    }
    if(dp[n]!=-1) return dp[n];
    int temp=n;
    int ans=1e9;
    while(temp>0){
        int d=temp%10;
        if(d!=0){
            ans=min(ans,1+solve(n-d,dp));
        }
        temp/=10;
    }
    return dp[n]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<solve(n,dp)<<endl;
}