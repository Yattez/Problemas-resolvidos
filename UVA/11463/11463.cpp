#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;

const int INF=(int)1e6;
int n,e,t;
vector<vector<int>>d(1000,vector<int>(1000,INF));

void makeset(){
	for(int i=0;i<=n+2;i++) {
		for(int j=0;j<=n+2;j++) {
			d[i][j]=INF;
		}
	}
	for(int i=0;i<=n+2;i++) {
		d[i][i]=0;
	}
}

void floyd(){	
	for(int k =0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if((d[i][k]+d[k][j]<d[i][j])) d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int x,y;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>e;
		makeset();
		for(int j=0;j<e;j++){
			cin>>x>>y;
			d[x][y]=1;
			d[y][x]=1;

		}
		floyd();
		cin>>x>>y;
		int maior=0;
		for(int j=0;j<n;j++){
			if(d[x][j]!=INF && d[j][y]!=INF)  maior=max(maior, d[x][j]+  d[j][y]);
		}
		cout<<"Case "<<i<<": "<<maior<<endl;
	}
}
