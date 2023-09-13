#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int int_fast32_t
const int inf=1e12;
const int mod=1e9+7;
 
using namespace std;
 
int n,m;
 
int x[]={1,0};
int y[]={0,1};
 
int dp[1005][1005];
char adj[1005][1005];
 
bool isValed(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m)return true;
	return false;
}
 
int contpath(int i,int j){
	if(adj[i][j]=='*')return 0;
	if(i==n-1 && j==m-1)return 1;
	
	if(dp[i][j]!=-1)return dp[i][j];
	
	int z=0;
	
	for(int k=0;k<2;k++){
		
		int u=i+x[k];
		int v=j+y[k];
		
		if(isValed(u,v)){
			z=z+contpath(u,v);
			z%=mod;
		}
	}
	return dp[i][j]=z;
}
 
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	
	cin>>n;
	m=n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>adj[i][j];
		}
	}
	cout<<contpath(0,0)<<endl;
}
