#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>adj(10005);
vector<bool>vis(10005);
int cont;

void dfs(int u){
    vis[u]=true;
    cont++;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    
}

int main() {
    int x,a,v,l,b,c,l1;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>v>>a>>l;
        cont=0;
        for(int j=0;j<a;j++){
            cin>>b>>c;
            adj[b].push_back(c);
        }
        for(int j=0;j<l;j++){
            cin>>l1;
            if(!vis[l1]){
                dfs(l1);
            }
        }
        cout<<cont<<endl;
        for(int j=0;j<10005;j++){
            adj[j].clear();
        }
        for(int j=0;j<10005;j++){
            vis[j]=false;
        }
    }
}
