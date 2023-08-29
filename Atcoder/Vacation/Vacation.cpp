#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int n;
vector<int>swim,bug,homework;
int dp[100000][4];

int voc(int i, int same){
	if(i==n)return 0;
	
	if(dp[i][same]!=-1)return dp[i][same];
	int x=0,y=0,z=0;
	if(same!=1) x=voc(i+1,1)+swim[i];
	if(same!=2) y=voc(i+1,2)+bug[i];
	if(same!=3) z=voc(i+1,3)+homework[i];
	
	return dp[i][same]=max(max(x,y),z);
	
}
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int s,b,h;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>s>>b>>h;
		swim.push_back(s);
		bug.push_back(b);
		homework.push_back(h);
	}
	cout<<voc(0,0)<<endl;
	
}
