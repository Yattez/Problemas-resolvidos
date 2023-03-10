#include <bits/stdc++.h>

using namespace std;

int contB;
int contP;
int contE;
int movesX[4]{-1,0,1,0};;
int movesY[4]{0,1,0,-1};
bool vis[9][9];
char graf[9][9];
vector<pair<int,int>>espaco;


bool isValid(int i, int j){
	if(i<0 || j<0 || i>=9|| j>=9 || vis[i][j] == true ){
		return false;
	}
	return true;
}

void ff(int x,int y){
	vis[x][y]=true;
	graf[x][y]='*';
	for(int i=0;i<4;i++){
		int nx=x+movesX[i];
		int ny=y+movesY[i];
		if(isValid(nx,ny)){
			
			if(graf[nx][ny]=='X'){
				contP++;
			}
			if(graf[nx][ny]=='O'){
				contB++;
			}
			
			if(graf[nx][ny]=='.'){
				contE++;
				//cout<<nx<<" "<<ny<<endl;
				ff(nx,ny);
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int tB=0;
		int tP=0;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>graf[i][j];
				if(graf[i][j]=='X'){
					tP++;
				}
				if(graf[i][j]=='O'){
					tB++;
				}
				if(graf[i][j]=='.'){
					espaco.push_back({i,j});
				}
			}
		}
		for(int i=0;i<espaco.size();i++){
			contB=0;
			contP=0;
			contE=1;
			if(!vis[espaco[i].first][espaco[i].second]){
				ff(espaco[i].first,espaco[i].second);
				if(contB==0){
					tP=tP+contE;
				}
				if(contP==0){
					tB=tB+contE;
				}
			}
		}
		cout<<"Black "<<tP<<" White "<<tB<<endl;
		espaco.clear();
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				vis[i][j]=false;
			}
		}
	}
}
