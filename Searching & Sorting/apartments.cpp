#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>men(n),apt(m);
    for(int i=0;i<n;i++){
        cin>>men[i];
    }
    for(int i=0;i<m;i++){
        cin>>apt[i];
    }
    sort(men.begin(),men.end());
    sort(apt.begin(),apt.end());
    int cnt=0, i=0, j=0;
    while(i<men.size() && j<apt.size()){
        int minv=men[i]-k, maxv=men[i]+k;
        while(j<apt.size() && apt[j]<minv){
            j++;
        }
        if(apt[j]<=maxv && apt[j]>=minv){
            cnt++;
            j++;
        }
        i++;
    }
    cout<<cnt<<endl;
}