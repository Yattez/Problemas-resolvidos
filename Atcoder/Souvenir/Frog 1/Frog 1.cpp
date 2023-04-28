#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int const inf=10e6;
vector<int>v;	

int dp[100500];

int knap(int i,int n){
	if(i==n-1)return 0;
	
	if(dp[i]!=-1)return dp[i];
	
	int x=inf,y=inf;
	x=abs(v[i]-v[i+1])+knap(i+1,n);
	
	if(i+2<n)y=abs(v[i]-v[i+2])+knap(i+2,n);
	
	return dp[i]=min(x,y);
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int n,x;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<knap(0,n)<<endl;
}
