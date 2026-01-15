#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
int M;
int solve(int i, int prev, vector<int>&nums, vector<vector<int>>&dp){
    if(i==nums.size()) return 1;
    if(prev!=0 && nums[i]!=0 && abs(nums[i]-prev)>1){
        return 0;
    }
    if(prev!=0 && dp[i][prev]!=-1) return dp[i][prev];
    int ans=0;
    if(nums[i]==0){
        if(prev==0){
            for(int j=1;j<=M;j++){
                ans+=solve(i+1,j,nums,dp);
                if(ans>=MOD) ans-=MOD;
            }
        }
        else {
                for(int j=-1;j<=1;j++){
                    if(prev+j>=1 && prev+j<=M){
                        ans+=solve(i+1,j+prev,nums,dp);
                        if(ans>=MOD) ans-=MOD;
                    }
                }
        }
    }
    else {
        ans = solve(i+1, nums[i], nums, dp);
    }

    if(prev != 0) dp[i][prev] = ans;
    return ans;
}
int main(){
    int n, m;
    cin>>n>>m;
    M=m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    cout<<solve(0,0,nums,dp);
}