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

int dp[100500];

int n;
vector<int>jump;

void makeset(){
	for(int i=0;i<=n+1;i++)dp[i]=inf;
}

int sapo(){
	
	dp[0]=0;
	for(int i=1;i<=n;i++){
		
		dp[i]=dp[i-1]+abs(jump[i]-jump[i-1]);
		if(i-2>=0){
			dp[i]=min(dp[i],dp[i-2]+abs(jump[i]-jump[i-2]));
		}
	}
	
	return dp[n-1];
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	cin>>n;
	int x;
	makeset();
	for(int i=0;i<n;i++){
		cin>>x;
		jump.push_back(x);
	}
	cout<<sapo()<<endl;
}
