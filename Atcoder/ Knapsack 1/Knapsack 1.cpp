#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int n,w;
vector<int>peso,valor;

int dp[200][200000];

int knap(int i,int p){
    if(i==n)return 0;

    if(dp[i][p]!=-1)return dp[i][p];

    int x=0,y=0;
    if( p-peso[i]>=0 )x=knap(i+1,p-peso[i])+valor[i];
    y=knap(i+1,p);
    
	return dp[i][p]=max(x,y);
}
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);]
    memset(dp,-1,sizeof(dp));
	cin>>n>>w;
    int p,v;
    for(int i=0;i<n;i++){
        cin>>p>>v;
        peso.push_back(p);
        valor.push_back(v);
    }
    cout<<knap(0,w)<<endl;
}
