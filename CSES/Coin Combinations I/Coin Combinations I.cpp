#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf=1e8;
const int mod=1e9+7;
 
using namespace std;
 
 
int n,sum;
 
vector<int>money;
int dp[3000005];
 
void makeset(){
	for(int i=0;i<3000005;i++){
		dp[i]=0;
	}
	
}
 
int coins(){
	dp[0]=1;
	for(int i=0;i<sum;i++){
		for(int j=0;j<n;j++){
			if(sum>=i+money[j])dp[i+money[j]]=dp[i+money[j]]+dp[i]%mod;
		}
	}
	return dp[sum]%mod;
}
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	cin>>n>>sum;
	makeset();
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		money.push_back(x);
	}
	cout<<coins()<<endl;
	
}
