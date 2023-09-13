#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf=1e8;
const int mod=1e9+7;
 
using namespace std;
 
int n;
 
int dp[1000050];
bool valid(int x,int y){
	string str=to_string(x+y);
	char c=y+48;
	if(dp[x+y]>dp[x]+1){
		for(int i=0;i<str.size();i++){
			if(str[i]==c)return true;
		}
	}
	return false;
	
}
 
int ff(){
	dp[0]=0;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=9;j++){
			if(valid(i,j)){
				dp[i+j]=dp[i]+1;
			}
		}
	}
	return dp[n];
}
 
 
	
signed main(){
	cin>>n;
	for(int i=0;i<=n;i++){
		dp[i]=inf;
	}
	cout<<ff()<<endl;
}
