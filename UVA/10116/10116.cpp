#include <bits/stdc++.h>

using namespace std;
bool vis[30][30];
char adj[30][30];
int dist[30][30];
int parouX,parouY;
int terminouX,terminouY;
int m,n;

bool dfs(int x,int y){
	vis[x][y]=true;
	char v=adj[x][y];
	int nx,ny;
    if(v=='W'){
		ny=y-1;
		nx=x;
	}
	else{
		if(v=='N'){
			nx=x-1;
			ny=y;
		}
		else{
			if(v=='S'){
				nx=x+1;
				ny=y;
			}
			else{
				ny=y+1;
				nx=x;
			}
		}
	}
	parouX=nx;
	parouY=ny;
	terminouX=x;
	terminouY=y;
	if(nx<0 || ny<0 || nx>=m ||ny>=n) return true;
    if(!vis[nx][ny]){
		dist[nx][ny]=dist[x][y]+1;
		return dfs(nx,ny);
	}
	
    return false;
}

int main(){
	int z;
	cin>>m>>n>>z;
	while(m!=0 || n!=0 || z!=0){
		memset(vis,false,sizeof(vis));
		memset(dist,0,sizeof(dist));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>adj[i][j];
			}
		}
		dist[0][z-1]=0;
		if(dfs(0,z-1)){
			
			cout<<dist[terminouX][terminouY]+1<<" step(s) to exit"<<endl;
		}
		else{
			cout<<dist[parouX][parouY]<<" step(s) before a loop of "<<dist[terminouX][terminouY]-dist[parouX][parouY]+1<<" step(s)"<<endl;
		}
		cin>>m>>n>>z;
	}
	
}
