#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf=1e8;
const int mod=1e9+7;
 
using namespace std;
int x[]={0,1,0,-1, 1,-1,1,-1};
int y[]={1,0,-1,0, 1,-1,-1,1};
 
int dp[2000050];
int n;
 
void makeset(){
	for(int i=0;i<=n+1;i++){
		dp[i]=-1;
	}
}
 
int dice(int sum){
	if(sum==0)return 1;
	if(sum<0)return 0;
	
	if(dp[sum]!=-1)return dp[sum];
	
	int z=0;
	for(int i=1;i<=6;i++){
		z+=dice(sum-i);
	}
	return dp[sum]=z%mod;
}
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n;
	
	makeset();
	cout<<dice(n)<<endl;
	
}
