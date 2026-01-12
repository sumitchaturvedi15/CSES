#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
vector<vector<int>>dp;
int solve(int i, int j, vector<string>&grid){
    if(i==grid.size() || j==grid.size() ||grid[i][j]=='*'){
        return 0;
    }
    if(i==grid.size()-1 && j==grid.size()-1){
        if(grid[i][j]=='.'){
            return 1;
        }
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int right=solve(i+1,j,grid), left=solve(i,j+1,grid);
    if(left+right>=MOD){
        return dp[i][j]=left+right-MOD;
    }
    return dp[i][j]=left+right;
}

int main(){
    int n;
    cin>>n;
    vector<string>grid(n);
    dp.resize(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    cout<<solve(0,0,grid)<<endl;
    return 0;
}