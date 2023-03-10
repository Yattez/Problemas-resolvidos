//BFS

#include <bits/stdc++.h>

using namespace std;

bool vis[1005][1005];
char jeff[1005][1005];
int fire[1005][1005];
int m,n;

int movesx[4]{0,1,-1,0};
int movesy[4]{1,0,0,-1};

void bfsfire(int origemx,int origemy){
	queue<pair<int,pair<int,int>>>q;
	q.push({1,{origemx,origemy}});
	fire[origemx][origemy]=q.front().first;
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=u.second.first+movesx[i];
			int ny=u.second.second+movesy[i];
			if(nx>=0 && nx<m && ny>=0 && ny<n && jeff[nx][ny]=='.' && fire[nx][ny]>u.first){
				fire[nx][ny]=u.first;
				q.push({u.first+1,{nx,ny}});
				
			}
		}
	}
}


int bfsjeff(int origemx,int origemy){
	queue<pair<int,pair<int,int>>>q;
	q.push({1,{origemx,origemy}});
	vis[origemx][origemy]=true;
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=u.second.first+movesx[i];
			int ny=u.second.second+movesy[i];
			if(nx<0 || ny<0 || nx>=m || ny>=n) return u.first;
			if(nx>=0 && nx<m && ny>=0 && ny<n && jeff[nx][ny]=='.' && fire[nx][ny]>u.first && vis[nx][ny]==false){
				
				vis[nx][ny]=true;
				q.push({u.first+1,{nx,ny}});
				
			}
		}
	}
	return -1;
}


int main(){
	int x;
	cin>>x;
	while(x--){
		cin>>m>>n;
		int si,sj;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>jeff[i][j];
				vis[i][j]=false;
				fire[i][j]=10000;
				if(jeff[i][j]=='J'){
					si=i;
					sj=j;
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(jeff[i][j]=='F'){
					bfsfire(i,j);
				}
			}
		}
		int h=bfsjeff(si,sj);
		if(h!=-1){
			cout<<h<<endl;
		}
		else{
			cout<<"IMPOSSIBLE"<<endl;
		}
	}
			
}
	
