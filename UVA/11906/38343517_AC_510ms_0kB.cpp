#include <bits/stdc++.h>

using namespace std;

int graf[105][105];
bool vis[105][105][105][105];
int r,c;
bool isValid(int i, int j,int x,int y){
	if(i<0 || j<0 || i>=r|| j>=c || x<0 || y<0 || x>=r|| y>=c || graf[i][j]==-1 || vis[x][y][i][j]==true){
		return false;
	}
	return true;
}

void dfs(int m,int n,int x,int y){
	int nx=x+m;
	int ny=y+n;
	if(isValid(nx,ny,x,y)){
		graf[x][y]++;
		vis[x][y][nx][ny]=true;
		dfs(m,n,nx,ny);
	}
	nx=x-m;
	ny=y+n;
	if(isValid(nx,ny,x,y)){
		graf[x][y]++;
		vis[x][y][nx][ny]=true;
		dfs(m,n,nx,ny);
	}
	nx=x+m;
	ny=y-n;
	if(isValid(nx,ny,x,y)){
		vis[x][y][nx][ny]=true;
		graf[x][y]++;
		dfs(m,n,nx,ny);
	}
	nx=x-m;
	ny=y-n;
	if(isValid(nx,ny,x,y)){
		graf[x][y]++;
		vis[x][y][nx][ny]=true;
		dfs(m,n,nx,ny);
	}
	nx=x+n;
	ny=y+m;
	if(isValid(nx,ny,x,y)){
		graf[x][y]++;
		vis[x][y][nx][ny]=true;
		dfs(m,n,nx,ny);
	}
	nx=x-n;
	ny=y+m;
	if(isValid(nx,ny,x,y)){
		graf[x][y]++;
		vis[x][y][nx][ny]=true;
		dfs(m,n,nx,ny);
	}
	nx=x+n;
	ny=y-m;
	if(isValid(nx,ny,x,y)){
		graf[x][y]++;
		vis[x][y][nx][ny]=true;
		dfs(m,n,nx,ny);
	}
	nx=x-n;
	ny=y-m;
	if(isValid(nx,ny,x,y)){
		graf[x][y]++;
		vis[x][y][nx][ny]=true;
		dfs(m,n,nx,ny);
	}
		
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,x,y,m,n,w;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>r>>c>>m>>n;
		
		int par=0,impar=0;
		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				graf[j][k]=0;
			}
		}
		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				for(int l=0;l<r;l++){
					for(int v=0;v<c;v++){
						vis[j][k][l][v]=false;
					}
				}
			}
		}
		cin>>w;
	for(int j=0;j<w;j++){
			cin>>x>>y;
			graf[x][y]=-1;
		}
		dfs(m,n,0,0);
		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				if(graf[j][k]!=0 && graf[j][k]!=-1){
					if(graf[j][k]%2==0 ){
						par++;
					}
					else{
						impar++;
					}
				}
			}
		}
		if(graf[0][0]==0){
			par++;
		}
		cout<<"Case "<<i+1<<": "<<par<<" "<<impar<<endl;
	}
}
