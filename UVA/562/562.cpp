#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int n;
vector<int>moedas;
int dp[105][50005];

int knap(int i,int s,int sum){
	if(i==(int)moedas.size() || s==sum/2)return s;	
	if(s>sum/2)return 0;
	
	if(dp[i][s]!=-1) return dp[i][s];
	int x=0,y=0;
	if(s+moedas[i]<=sum/2) x=knap(i+1,s+moedas[i],sum);
	if(s<=sum/2)y=knap(i+1,s,sum);
	return dp[i][s]=max(x,y);
}
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int t,m,sum;
	cin>>t;
	while(t--){
		moedas.clear();
		memset(dp,-1,sizeof(dp));
		sum=0;
		cin>>n;
		if(n!=0){
			for(int i=0;i<n;i++){
				cin>>m;
				moedas.push_back(m);
				sum+=m;
			}
			int h=knap(0,0,sum);
			int g=sum-h;
			cout<<abs(g-h)<<endl;
		}
		else cout<<0<<endl;
	}
}
