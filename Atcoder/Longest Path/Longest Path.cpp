#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int n,m;

vector<int>adj[100005];
bool vis[100005];
int dp[100005];

void dfs(int u){
	vis[u]=true;
	
	for(auto v:adj[u]){
		if(!vis[v]){
			dfs(v);
		}
		dp[u]=max(dp[u],1+dp[v]);
	}
}
int longpath(){
	for(int i=0;i<n;i++) if(!vis[i])dfs(i);
	
	int ans = 0;
    for(int i=0;i<n;i++)ans = max(ans, dp[i]);
   
    return ans;
}

	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		x--,y--;
		adj[x].push_back(y);
	}
	cout<<longpath()<<endl;

}
	

