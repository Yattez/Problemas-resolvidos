#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;


vector<pair<int,pair<int,int>>>adj(10000);
int dist[10000];
const int inf=(int)1e6;
int n,e;

void makeset(){
	for (int i = 0; i < n+2; i++)dist[i] = inf;
}

bool bellman(){
	makeset();
	dist[0] = 0;
	for(int i =1;i<n;i++) {
		for(int j=0;j<e;j++) {
			int u =adj[j].f;
			int v = adj[j].s.f;
			int weight =adj[j].s.s;
			if (dist[u] !=inf && dist[u] + weight < dist[v]) dist[v] = dist[u] + weight;
		}
	}
	for (int i = 0; i < e; i++) {
		int u =adj[i].f;
		int v = adj[i].s.f;
		int weight =adj[i].s.s;
		if (dist[u] != inf && dist[u] + weight < dist[v]) {
			return true;
		}
	}
	return false;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	int t;cin>>t;
	while(t--){
		cin>>n>>e;
		int x,y,z;
		for(int i=0;i<e;i++){
			cin>>x>>y>>z;
			adj[i].f=x;
			adj[i].s.f=y;
			adj[i].s.s=z;
		}
		if(bellman())cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
}
