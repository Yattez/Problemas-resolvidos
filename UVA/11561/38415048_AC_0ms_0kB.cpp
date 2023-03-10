#include <bits/stdc++.h>

using namespace std;
int movesX[4]={-1,0,1,0};
int movesY[4]={0,1,0,-1};
bool vis[60][60];
char m[60][60];
int h,w;
int cont=0;

bool isValid(int i, int j){
	if(i<0 || j<0 || i>=h || j>=w || vis[i][j]==true || m[i][j]=='#' ||m[i][j]=='T'){
	//~ ||m[i-1][j]=='T'||m[i][j+1]=='T'||m[i+1][j]=='T'||m[i][j-1]=='T'){
		return false;
	}
	return true;
}
bool isTrap(int i, int j){
	if(m[i-1][j]=='T'||m[i][j+1]=='T'||m[i+1][j]=='T'||m[i][j-1]=='T'){
		return false;
	}
	return true;
}
void ff(int x,int y){
	vis[x][y]=true;
	if(m[x][y]=='G') cont++;
	if(isTrap(x,y)){
		for(int i=0;i<4;i++){
			int nx=x+movesX[i];
			int ny=y+movesY[i];
			if(isValid(nx,ny)){
				ff(nx,ny);
			}
		}
	}
}
			
int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	while(cin>>w>>h){
		memset(vis,false,sizeof(vis));
		int pX,pY;
		cont=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>m[i][j];
				if(m[i][j]=='P'){
					pX=i;
					pY=j;
				}
			}
		}
	
		ff(pX,pY);
		cout<<cont<<endl;
	}
}
