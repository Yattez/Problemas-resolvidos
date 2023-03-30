#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;


vector<pair<int,pair<int,int>>>adj(10000);
vector<int>dist1(1000);
vector<int>dist2(1000);
const int inf=(int)1e9;
int n,e,z;

void makeset(){
	for (int i = 0; i < n+2; i++)dist1[i] = inf;
}

bool bellman(int start){
	makeset();
	dist1[start]=0;
	for(int i=1;i<n;i++) {
		for(int j=0;j<e;j++) {
			int u=adj[j].f;
			int v=adj[j].s.f;
			int weight=adj[j].s.s;
			if (dist1[u]!=inf && dist1[u]+weight<dist1[v]) dist1[v]=dist1[u] + weight;
		}
	}
	for (int i=0; i < n+2; i++)dist2[i]=dist1[i];
	
	for (int i=0;i<e;i++) {
		int u=adj[i].f;
		int v=adj[i].s.f;
		int weight=adj[i].s.s;
		if (dist2[u]!=inf && dist2[u]+weight<dist2[v]) {
			dist2[v]=dist2[u] + weight;
			//~ cout<<dist2[v]<<endl;
		}
	}
	for (int i=0;i<n;i++) {
		if(dist1[i]>dist2[i])return true;
		else dist1[i]=dist2[i];
	}
	return false;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int cont=1;
	while(cin>>n){
		int b[n+1];
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		cin>>e;
		int x,y;
		for(int i=0;i<e;i++){
			
			cin>>x>>y;
			x--;
			y--;
			adj[i].f=y;
			adj[i].s.f=x;
			adj[i].s.s=pow((b[y]-b[x]),3);
			//~ cout<<adj[i].f<<" "<<adj[i].s.f<<" = "<<adj[i].s.s<<endl;
		}
		int q;
		cin>>q;
		
		cout<<"Set #"<<cont++<<endl;
		for(int i=0;i<q;i++){
			cin>>z;
			z--;
			if(bellman(z) || dist1[0]<3 || dist1[0]==inf)cout<<'?'<<endl;
			else cout<<dist1[0]<<endl;			
		}
	}
}
