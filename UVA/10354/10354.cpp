#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;

int n,e,bh,of,mh,m;

const int INF=(int)1e6;
vector<vector<int>>d(1000,vector<int>(1000));
vector<vector<int>>c(1000,vector<int>(1000));
bool vis[1000];

void find(){
	for( int i=1; i<=n; ++i ){
		if(d[bh][of]==d[bh][i]+d[i][of])vis[i]=true;
	}
}
void makeset(){
	for(int i=0;i<=n+2;i++) {
		for(int j=0;j<=n+2;j++) {
			d[j][i]=d[i][j]=INF;
			c[j][i]=c[i][j]=INF;
		}
	}
	for(int i=0;i<=n+2;i++) {
		d[i][i]=0;
		c[i][i]=0;
		vis[i]=false;
	}
}


void floyd1(){	
	for(int k =1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if((d[i][k]+d[k][j]<d[i][j]))d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
}


void floyd2(){	
	for(int k =1;k<=n;k++) {
		if(!vis[k]){
			for(int i=1;i<=n;i++) {
				if(!vis[i]){
					for(int j=1;j<=n;j++) {
						if(!vis[j]){
							if((c[i][k]+c[k][j]<c[i][j]) ){
								c[i][j]=c[i][k]+c[k][j];
							}
						}
					}
				}
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	while(cin>>n>>e>>bh>>of>>mh>>m){
		makeset();
		int x,y,z;
		set<int>btreck;
		for(int i=0;i<e;i++){
			cin>>x>>y>>z;
			string aux1=to_string(x);
			string aux2=to_string(y);
			d[x][y]=z;
			d[y][x]=z;
			c[y][x]=z;
			c[x][y]=z;
		}
		floyd1();
		find();
		floyd2();
		if((c[mh][m]!=INF) && (!vis[mh]&& !vis[m]))cout<<c[mh][m]<<endl;
		else cout<<"MISSION IMPOSSIBLE."<<endl;
	}
}
