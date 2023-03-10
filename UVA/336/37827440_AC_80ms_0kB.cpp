#include <bits/stdc++.h>

using namespace std;

map<int,vector<int>>adj;
map<int,bool>vis;
map<int,int>dist;

void bfs(int origem){
	queue<int>q;
	q.push(origem);
	vis[origem]=true;
	dist[origem]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			if(!vis[v]){
				q.push(v);
				vis[v]=true;
				dist[v]=dist[u]+1;
			}
		}
	}
}

int main(){
	int n,x,y,z,a,b,cont=1;
	cin>>n;
	while(n!=0){
		for(int i=0;i<n;i++){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			vis[x]=false;
			vis[y]=false;
			dist[x]=-1;
			dist[y]=-1;
		}
		cin>>a>>b;
		while(a!=0 ||  b!=0){
			z=0;
			bfs(a);
			for(auto it:dist){
				if(it.second>b || it.second==-1){
					z++;
				}
			}
			cout<<"Case "<<cont<<": "<<z<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
			cont++;
			for(auto it: dist){
				dist[it.first]=-1;
			}	
			for(auto it: vis){
				vis[it.first]=false;
			}
			cin>>a>>b;
		}
		adj.clear();
		vis.clear();
		dist.clear();
		cin>>n;
	}
}
