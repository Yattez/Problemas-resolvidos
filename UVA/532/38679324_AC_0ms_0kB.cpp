#include <bits/stdc++.h>

using namespace std;

int x,y,z;

char m[35][35][35];
bool vis[35][35][35];

int movesZ[2]={1,-1};
int movesX[4]={0,1,0,-1};
int movesY[4]={1,0,-1,0};

int bucetinha = 0;

bool isValid(int i,int j,int k){
	if(i>=0 && j >= 0 && k>=0 && i<z && j<x && k<y && (m[i][j][k] == '.' || m[i][j][k]=='E') && !vis[i][j][k])
	{
		return true;
	}
	return false;
	
}

int bfs(int cz,int cx,int cy){
	vis[cz][cx][cy]=true;
	queue<pair<int,pair<int,pair<int,int>>>>q;
	q.push({cz,{cx,{cy,0}}});
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int nz=u.first+movesZ[i];
			int nx=u.second.first;
			int ny=u.second.second.first;
			int cont=u.second.second.second;
			if(isValid(nz,nx,ny)){
				vis[nz][nx][ny]=true;
				q.push({nz,{nx,{ny,cont+1}}});
			}
		}
		if(m[u.first][u.second.first][u.second.second.first]=='E') return u.second.second.second;
		for(int j=0;j<4;j++){
			int nz=u.first;
			int nx=u.second.first+movesX[j];
			int ny=u.second.second.first+movesY[j];
			int cont=u.second.second.second;
			if(isValid(nz,nx,ny)){
				vis[nz][nx][ny]=true;
				q.push({nz,{nx,{ny,cont+1}}});				
			}
		}
	}
	return -1;
}

int main(){
	cin>>z>>x>>y;
	while(x || y || z){
		int sz,sy,sx;
		for(int i=0;i<z;i++){
			for(int j=0;j<x;j++){
				for(int k=0;k<y;k++){
					cin>>m[i][j][k];
					vis[i][j][k]=false;
					if(m[i][j][k]=='S'){
						sz=i;
						sx=j;
						sy=k;
					}
				}
			}
		}
		
		int t=bfs(sz,sx,sy);
		if(t!=-1){
			cout<<"Escaped in "<<t<<" minute(s)."<<endl;
		}
		else{
			cout<<"Trapped!"<<endl;
		}
		cin>>z>>x>>y;
		
	}
	
}
