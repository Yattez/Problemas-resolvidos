#include <bits/stdc++.h>

using namespace std;
int n,m;
bool vis[10010];
int timer[10010];
int low[10010];
vector <int> adjList[10010];
int tps = 0;
int cont=0;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dfs(int u, int p = -1){
	vis[u] = true;
	timer[u] = low[u] = tps++;
	//int filho = 0;
	for(int v:adjList[u]){
		//if(v == p) continue;
		if(!vis[v]){
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(timer[u]< low[v]){
				// aresta u-v é ponte
				pq.push({min(u,v),max(u,v)});
				cont++;
			}
			//~ if(timer[u] <= low[v] and p != -1){
				//~ // vertice u  é ponto de aticulação
			//~ }
			//~ filho++;
		}
		else if (v!=p){
			low[u] = min(low[u], timer[v]);
		}
		//~ if(p == -1 and filho > 1){
			//~ // u é ponto de articulação, so pra resolver o problema de um vertice possuir so um filho
			//~ cout<<u<<' '<<v<<endl;
		//~ }
	}
}

int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>m;
	while(n!=0 || m!=0){
		int x,y;
		
		while(m--){
			cin>>x>>y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		cont=0;
		tps=0;
		for (int j = 0; j < n; j++) {
			if(!vis[j]){
				dfs(j);
			}
		}
		cout<<cont;
		while(!pq.empty()){
			cout<<' '<<pq.top().first<<' '<<pq.top().second;
			pq.pop();
		}
		for(int j=0;j<n;j++){
			vis[j]=false;
			timer[j]=0;
			low[j]=0;
			adjList[j].clear();
		}
		cout<<endl;
		cin>>n>>m;
	}
}
