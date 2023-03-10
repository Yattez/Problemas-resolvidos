#include <bits/stdc++.h>

using namespace std;

char ma[25][25];
bool vis[25][25];

int movesX[4]={0,1,0,-1};
int movesY[4]={1,0,-1,0};

char c;
int m,n;
int save,ct;

bool isValid(int i,int j){
	if(j>=0 && i>= 0 && j<n && i<m && ma[i][j]==c && vis[i][j]==false){
		return true;
	}
	return false;
	
}

void dfs(int x,int y){
	vis[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+movesX[i];
		int ny=y+movesY[i];
		if(ny<0){
			ny=n-1;
		}
		else{
			ny=ny%n;
		}
		if(isValid(nx,ny)){
			ct++;
			dfs(nx,ny);
		}
	}
}

int main(){
	int x,y;
	int h=0;
	while(cin>>m>>n){
		h++;
		save=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>ma[i][j];
				vis[i][j]=false;
			}
		}
		cin>>x>>y;
		c=ma[x][y];
		ma[x][y]='S';
		dfs(x,y);
		
		ct=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(!vis[i][j] && ma[i][j]==c){
					ma[i][j]='*'	;
					dfs(i,j);
					if(save<ct){
						save=ct;
					}
					ct=1;
				}
			}
		}
		cout<<save<<endl;
	}
}
