#include <bits/stdc++.h>

using namespace std;

int adj[8][8];
bool vis[8][8];
int dist[8][8];

int movesX[8]={-2,-2,-1,-1,1,1,2,2};
int movesY[8]={-1,1,2,-2,-2,2,-1,1};

int bfs(pair<int,int> origem,pair<int,int> destino){
	queue<pair<int,int>>q;
	q.push(origem);
	vis[origem.first][origem.second]=true;
	dist[origem.first][origem.second]=0;
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int nx=u.first+movesX[i],ny=u.second+movesY[i];
			if(nx>=0&& ny>=0 && nx<8 && ny<8 &&!vis[nx][ny]){
				q.push({nx,ny});
				vis[nx][ny]=true;
				dist[nx][ny]=dist[u.first][u.second]+1;
			}
		}
	}
	return dist[destino.first][destino.second];
}


int main(){
	char X1,X2;
	int Y1,Y2,a,b;
	while(cin>>X1>>Y1>>X2>>Y2){
		a=X1-'a';
		b=X2-'a';
		pair<int,int>ori={a,Y1-1},des{b,Y2-1};
		cout<<"To get from "<<X1<<Y1<<" to "<<X2<<Y2<<" takes "<<bfs(ori,des)<<" knight moves."<<endl;
		memset(adj,0,sizeof(adj));
		memset(vis,false,sizeof(vis));
		memset(dist,0,sizeof(dist));
	}
}
