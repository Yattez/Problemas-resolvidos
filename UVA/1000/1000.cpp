#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;



const int inf=(int)10e6;
vector<int>adj[1000];
int vis[1000];
int peso[1000];
int dist[1000];
stack<int>Stack;
int in,n;



void makeset(){
	for (int i = 0; i < 1000; i++){
		vis[i] = false;
		adj[i].clear();
		peso[i]=0;	
	}
	while(!Stack.empty()){
		Stack.pop();
	}
}

void topologicalSortUtil(int v)
{
	vis[v] = true;
	for (auto u: adj[v]) {
		if(!vis[u])
			topologicalSortUtil(u);
	}
	Stack.push(v);
}


void DAG(){
	for (int i = 0; i < n; i++){
		if (vis[i] == false){
			topologicalSortUtil(i);
		}
	}
	for (int j=0;j<n;j++)dist[j]=-inf;
	dist[in]=0;
	while (!Stack.empty()) {
		int v = Stack.top();
		Stack.pop();
		if (dist[v] != -inf) {
			for (auto u: adj[v]) {
				if (dist[u] < dist[v] + peso[u]){
					dist[u] = dist[v] + peso[u];
				}
			}
		}
	}
	int maior=-12,save=0;
	for (int k = 0; k < n; k++){
		if(dist[k]!=inf && dist[k]>maior){
			maior=dist[k];
			save=k;
		}
	}
	cout<<"The longest path from "<<in+1<<" has length "<<maior<<", finishing at "<<save+1<<"."<<endl<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int cont=0;
	cin>>n;
	while(n!=0){
		makeset();
		cin>>in;
		in--;
		int x,y;
		cin>>x>>y;
		while(x!=0 || y!=0){
			x--;
			y--;
			adj[x].push_back(y);
			peso[x]=1;
			peso[y]=1;
			cin>>x>>y;
		}
		cout<<"Case "<<++cont<<": ";
		DAG();
		cin>>n;
	}
}
