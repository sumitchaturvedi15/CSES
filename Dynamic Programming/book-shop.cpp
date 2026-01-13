#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(int i, int x, vector<int>&prices, vector<int>&pages, vector<vector<ll>>&dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[i][x]!=-1) return dp[i][x];
    ll take=0;
    if(x>=prices[i]){
        take=pages[i]+solve(i+1,x-prices[i],prices,pages,dp);
    }
    ll nottake=solve(i+1,x,prices,pages,dp);
    return dp[i][x]=max(take,nottake);
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>prices(n),pages(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    // vector<vector<ll>>dp(n,vector<ll>(x+1,0));
    vector<ll>dp(x+1,0), next(x+1,0);
    for(int j=0;j<=x;j++){
        if(prices[n-1]<=j){
            next[j]=pages[n-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=x;j++){
            ll take=0,nottake=0;
            if(j>=prices[i]){
                take=pages[i]+next[j-prices[i]];
            }
            nottake=next[j];
            dp[j]=max(take,nottake);
        }
        next=dp;
    }
    cout<<dp[x]<<endl;
    return 0;
}