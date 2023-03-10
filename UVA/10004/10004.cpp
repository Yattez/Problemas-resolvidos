#include <bits/stdc++.h>

using namespace std;
bool vis[220];
vector<int>adj[220];
bool color[220];

bool Bipartite(int v){
	vis[v]=true;
    for (int u : adj[v]){
        if (vis[u] == false){
            color[u] = !color[v];
            if(!Bipartite(u)) return false;
        }
        else{
			if (color[u] == color[v]) return false;
		}
    }
    return true;
}

int main(){
	int n,l,x,y;
	cin>>n;
	while(n!=0){
		cin>>l;
		memset(vis,false,sizeof(vis));
		memset(color,false,sizeof(color));
		for(int x=0;x<n;x++){
			adj[x].clear();
		}
		for(int j=0;j<l;j++){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		if(Bipartite(0)){
			cout<<"BICOLORABLE."<<endl;
		}
		else{
			cout<<"NOT BICOLORABLE."<<endl;
		}
		cin>>n;
	}
}
