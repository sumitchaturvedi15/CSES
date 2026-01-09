#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>weights(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    sort(weights.begin(),weights.end());
    int need=0, l=0, r=n-1;
    while(l<=r){
        if(l==r){
            need++;
            r--;
        }
        else if(weights[l]+weights[r]<=x){
            need++;
            l++,r--;
        }
        else {
            need++;
            r--;
        }
    }
    cout<<need<<endl;
    return 0;
}