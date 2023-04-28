#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int const inf=10e7;
vector<int>v;	

int dp[100500];

int knap(int i,int n,int k){
	if(i>=n-1)return 0;
	
	if(dp[i]!=-1)return dp[i];
	
	
	int y=abs(v[i]-v[i+1])+knap(i+1,n,k);
	for(int j=2;j<=k;j++){
		if(i+j<n){
			y=min(y,abs(v[i]-v[i+j])+knap(i+j,n,k));
		}
		
	}
	
	return dp[i]=y;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	memset(dp,-1,sizeof(dp));
	
	int n,x,k;
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<knap(0,n,k)<<endl;
}
