#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int int_fast32_t
const int inf=1e12;
const int mod=1e9+7;
 
using namespace std;
 
int n,x;
 
vector<int>dp(100500,0);
vector<int>peso;
vector<int>pag;
 
 
int books(){
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=x;j>=peso[i];j--){
			dp[j]=max(dp[j],dp[j-peso[i]]+pag[i]);
		}
	}
		
	return dp[x];
	
}
 
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>x;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		peso.push_back(a);
	}
	for(int i=0;i<n;i++){
		cin>>a;
		pag.push_back(a);
	}
	cout<<books()<<endl;
}
