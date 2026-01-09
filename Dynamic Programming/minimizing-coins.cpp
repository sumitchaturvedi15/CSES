#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main(){
    ll n, target;
    cin>>n>>target;
    vector<ll>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<ll>dp(target+1,LLONG_MAX);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int t=1;t<=target;t++){
            if(t>=coins[i] && dp[t-coins[i]]!=LLONG_MAX){
                dp[t]=min(dp[t],1+dp[t-coins[i]]);
            }
        }
    }
    cout<<(dp[target]==LLONG_MAX?-1:dp[target])<<endl;
    return 0;
}