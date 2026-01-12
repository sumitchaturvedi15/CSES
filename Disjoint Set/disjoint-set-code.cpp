#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        //for size
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int u_parent=findParent(u);
        int v_parent=findParent(v);
        if(u_parent==v_parent){
            return;
        }
        if(rank[u_parent]<rank[v_parent]){
            parent[u_parent]=v_parent;
        }
        else if(rank[v_parent]<rank[u_parent]){
            parent[v_parent]=u_parent;
        }
        else{
            parent[v_parent]=u_parent;
            rank[u_parent]++;
        }
    }

    void unionBySize(int u, int v){
        int u_parent=findParent(u);
        int v_parent=findParent(v);
        if(u_parent==v_parent) return;
        if(size[u_parent]<size[v_parent]){
            parent[u_parent]=v_parent;
            size[v_parent]+=size[u_parent];
        }
        else{
            parent[v_parent]=parent[u_parent];
            size[u_parent]+=size[v_parent];
        }
    }
};

int main(){
    return 0;
}