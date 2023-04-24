#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int dp[1050][35];
int k[1050];
int l[1050];
int pm,t,n,p;

int knap(int i,int p){
	if(n==i) return 0;
	if(dp[i][p] != -1)return dp[i][p];
	int x=-2,y;
	if(p+k[i]<=pm)x=knap(i+1,p+k[i])+l[i];
	y=knap(i+1,p);
	return dp[i][p]=max(x,y);
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		int x,y,sum;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			k[i]=y;
			l[i]=x;
		}
		cin>>p;
		sum=0;
		while(p--){
			for(int j=0;j<n;j++)
				for(int k=0;k<35;k++)
					dp[j][k]=-1;
			cin>>pm;
			sum+=knap(0,0);
		}
		cout<<sum<<endl;
	}
	
}
