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
		dp[i]=0;
	}
}
 
int dice(int sum){
	
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=6;j++){
			dp[i] %= mod;
			if(i+j<=sum){
				dp[i+j]+=dp[i];
			}
		}
	}
	return dp[sum] % mod;
	
}
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n;
	
	makeset();
	cout<<dice(n)<<endl;
	
}
