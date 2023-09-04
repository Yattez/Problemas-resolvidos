#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf=1e16;
const int mod=1e9+7;

using namespace std;
int x[]={0,1,0,-1, 1,-1,1,-1};
int y[]={1,0,-1,0, 1,-1,-1,1};

int dp[505000];

int n,k;
vector<int>jump;

void makeset(){
	for(int i=0;i<505000;i++)dp[i]=inf;
}

int sapo(){
	
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i-j>=0) dp[i]= min(dp[i],dp[i-j]+abs(jump[i]-jump[i-j]));
		}
	}
	
	return dp[n-1];
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	cin>>n>>k;
	int x;
	makeset();
	for(int i=0;i<n;i++){
		cin>>x;
		jump.push_back(x);
	}
	cout<<sapo()<<endl;
}
