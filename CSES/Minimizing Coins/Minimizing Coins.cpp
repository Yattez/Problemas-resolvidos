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
int n,sum;
 
vector<int>money;
 
void makeset(){
	for(int i=0;i<=sum;i++){
		dp[i]=inf;
	}
}
 
int coins(int sum){
	
	dp[0]=0;
	for(int i=1;i<=sum;i++){
		for(int j=0;j<money.size();j++){
			if(i>=money[j]){
				dp[i]=min(dp[i],dp[i-money[j]]+1);
				
			}
		}
	}
	return dp[sum];
	
}
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int x;
	
	cin>>n>>sum;
	makeset();
	
	for(int i=0;i<n;i++){
		cin>>x;
		money.push_back(x);
	}
	int c=coins(sum);
	if(c==inf)cout<<-1<<endl;
	else  cout<<c<<endl;
}
