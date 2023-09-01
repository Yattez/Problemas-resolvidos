
#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf=1e8;
const int mod=1e9+7;

using namespace std;


int n;

vector<double>money;
double dp[3005][3005];

double coin(int i,int cara){
	if(i==n){
		if(cara>n/2)return 1;
		return 0;
	}
	if(dp[i][cara]!=-1)return dp[i][cara];
	
	double x=0,y=0;
	
	x=coin(i+1,cara+1)*money[i];
	y=coin(i+1,cara)*abs((1-money[i]));
	return dp[i][cara]=x+y;
}
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	
	cout<<fixed<<setprecision(9);
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=-1;
		
		}
	}
	
	double m;
	for(int i=0;i<n;i++){
		cin>>m;
		money.push_back(m);
		
	}
	cout<<coin(0,0)<<endl;
}
	
