#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf = 1e18;
using namespace std;

int n,w;
vector<int>peso,valor;

int dp[200][200000];
int knap(int i,int v){
	if(v == 0) return 0;
	if(i == n)return inf;
	
	if(dp[i][v]!=-1) return dp[i][v];
	int x = knap(i + 1, v);
	if(v - valor[i] >= 0) x = min(x, knap(i+1,v-valor[i])+peso[i]);
	return dp[i][v]=x;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n>>w;
    int p,v,total=0;
    for(int i=0;i<n;i++){
        cin>>p>>v;
        peso.push_back(p);
        valor.push_back(v);
        total+=v;
    }
	int ans;
	for(int i = total; i >= 0; i--) {
		int x = knap(0, i);
		if(x <= w) {
			ans = i;
			break;
			//ans = max(ans, i);
		}	
	}
	
	cout << ans << '\n';
}

