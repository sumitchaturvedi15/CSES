#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int solve(int i, int target, vector<int>&coins, vector<vector<int>>&dp){
    if(target==0) return 1;
    if(i==coins.size()) return 0;
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int take=0;
    if(coins[i]<=target){
        take=solve(i,target-coins[i],coins,dp);
    }
    int nottake=solve(i+1,target,coins,dp);
    return dp[i][target]=take+nottake;
}
int main(){
    int n, target;
    cin>>n>>target;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    // vector<vector<int>>dp(n,vector<int>(target+1,-1));
    vector<long long>dp(target+1,0),next(target+1,0);
    // cout<<solve(0,target,coins,dp);
    next[0]=1;
    for(int i=n-1;i>=0;i--){
        dp[0]=1;
        for(int t=1;t<=target;t++){
            long long take=0;
            if(coins[i]<=t){
                take=dp[t-coins[i]];
            }
            long long nottake=next[t];
            dp[t]=take+nottake;
            if(dp[t]>=mod) dp[t]-=mod;
        }
        next=dp;
    }
    cout<<dp[target]<<endl;
}