#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int movesX[4]={-1,1,0,0};
int movesY[4]={0,0,1,-1};
int n,m;
char mapa[58][58];
bool vis[58][58];
int entra[58][58];
int cont=0;
int jogadas=0;



vector<pair<int,int>>Xs;


bool isValid(int i, int j){
	if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==true|| mapa[i][j]=='.'){
		return false;
	}
	return true;
}


void dfs2(int x,int y){
	entra[x][y]=cont;
	if(mapa[x][y]=='X'){
		for(int i=0;i<4;i++){
			int nx=x+movesX[i];
			int ny=y+movesY[i];
			if(isValid(nx,ny)){
				if(mapa[nx][ny]=='X' && entra[nx][ny]==0){
					dfs2(nx,ny);
				}
			}
			
		}
	}
}
	
	
void dfs1(int x,int y){
	if(mapa[x][y]=='X'){
		entra[x][y]=cont;
		dfs2(x,y);
	 }
	vis[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+movesX[i];
		int ny=y+movesY[i];
		if(isValid(nx,ny)){
			if(mapa[nx][ny]=='X' && entra[nx][ny]==0){
				cont++;
			}
			dfs1(nx,ny);
		}
		
	}
}




int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>m>>n;	
	priority_queue<int,vector<int>,greater<int>>pq;
	while(m || n){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mapa[i][j];
				if(mapa[i][j]=='X') Xs.push_back({i,j});
			}
		}
		cout<<"Throw "<<++jogadas<<endl;
		for(int i=0;i<int(Xs.size());i++){
			cont=1;
			if(!vis[Xs[i].first][Xs[i].second]){
				dfs1(Xs[i].first,Xs[i].second);
				pq.push(cont);
				
			}
		}
		
		cout<<pq.top();
		pq.pop();
		while(!pq.empty()){
			cout<<" "<<pq.top();
			pq.pop();
		}
		cout<<endl;
		cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				vis[i][j]=false;
				entra[i][j]=false;
			}
		}
		Xs.clear();
		cin>>m>>n;
	}

}
