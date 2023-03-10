#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int inf=1000000;
vector<int>adj[1020];
vector<int>pe;
int vd[1020];


int h, m,n,p,x,y;

pair<int,int> dfs(int u){
	priority_queue<pair<int,int>>pq;
	for(auto v :adj[u]){
		pq.push({vd[u]+pe[v],v});
	}
	int v = pq.top().second;
	if(adj[v].size()==0)
		return pq.top();		
	vd[v]=vd[u]+pe[v];
	return dfs(v);
	
}

int main(){
	
	fast;
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>h;
	for(int i=1;i<=h;i++){
		cout<<"Case "<<i<<": ";
		cin>>m>>n;
		for(int j=0;j<m;j++){
			cin>>p;
			pe.push_back(p);
		}
		for(int j=0;j<n;j++){
			cin>>x>>y;
			adj[x].push_back(y);
		}
		pair<int,int>esse = dfs(0);
		cout<<esse.first<<" "<<esse.second<<endl;
		pe.clear();
		for(int j=0;j<m+1;j++){
			adj[j].clear();
			vd[j]=0;
		}
	}
	
}
