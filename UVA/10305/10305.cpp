#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>adj(105);
vector<bool>vis(105);
vector<int>ordem;

void dfs(int u){
    vis[u]=true;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    ordem.push_back(u);
}

int main() {
    int v,a,c,b;
    cin>>v>>a;
    while(v!=0 || a!=0){
       for(int i=0;i<a;i++){
           cin>>b>>c;
           adj[b].push_back(c);
       }
       for(int i=1;i<=v;i++){
           if(!vis[i]){
               dfs(i);
           }
       }
       for(int i=ordem.size()-1;i>0;i--){
           cout<<ordem[i]<<' ';
       }
       cout<<ordem[0];
       for(int i=0;i<105;i++){
           adj[i].clear();
       }
       for(int i=0;i<105;i++){
           vis[i]=false;
       }
       ordem.clear();
       cout<<endl;
       cin>>v>>a;
   }
}
