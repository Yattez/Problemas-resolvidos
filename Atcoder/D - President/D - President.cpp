#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int int_fast32_t
const int inf=1e12;
const int mod=1e9+7;

using namespace std;

int n;
vector<int>x;
vector<int>y;
vector<int>z;
vector<vector<int>>dp(150,vector<int>(100500,inf));

int president (){
	dp[0][0]=0;
	int cont=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=cont;j++){
			int k=0;
			if(x[i] < y[i]){
				k = ((y[i] - x[i]) + 1)/2;
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			} 
			dp[i+1][j+z[i]] = min(dp[i+1][j+z[i]],dp[i][j]+k);
		}
		cont+=z[i];
	}
	int m=inf;
	for(int i=(cont + 1)/2;i<=cont;i++){
		m=min(m,dp[n][i]);
	}
	return m;
}

	
signed main(){

	cin>>n;
	
	int a,b,c;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		x.push_back(a);
		y.push_back(b);
		z.push_back(c);
	}
	cout<<president()<<endl;
}
	
 
