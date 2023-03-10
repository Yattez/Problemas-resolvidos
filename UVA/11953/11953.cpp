#include <bits/stdc++.h>

using namespace std;

int movesX[4]={-1,1,0,0};
int movesY[4]={0,0,1,-1};
bool vis[105][105];
char m[105][105];
int n;
int cont=0;

bool isValid(int i, int j){
	if(i<0 || j<0 || i>=n || j>=n || vis[i][j]==true|| m[i][j]=='.'){
		return false;
	}
	return true;
}
void ff(int x,int y){
	vis[x][y]=true;
	for(int i=0;i<2;i++){
		int nx=x+movesX[i];
		int ny=y+movesY[i];
		if(isValid(nx,ny)){
			ff(nx,ny);
		}
	}
	for(int i=2;i<4;i++){
		int nx=x+movesX[i];
		int ny=y+movesY[i];
		if(isValid(nx,ny)){
			ff(nx,ny);
		}
	}
}
			
int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int x;
	cin>>x;
	for(int k=0;k<x;k++){
		memset(vis,false,sizeof(vis));
		cin>>n;
		vector<pair<int,int>>vx;
		cont=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>m[i][j];
				if(m[i][j]=='x'){
					vx.push_back({i,j});
				}
			}
		}
		for(int i=0;i<vx.size();i++){
			if(vis[vx[i].first][vx[i].second]==false){
				cont++;
				ff(vx[i].first,vx[i].second);
			}
		}
		cout<<"Case "<<k+1<<": "<<cont<<endl;
	}
}
