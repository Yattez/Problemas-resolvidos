#include <bits/stdc++.h>

using namespace std;

char ma[55][55];
bool vis[55][55];
int m,n,cont;
char c;
vector<pair<char,int>>save;

int movesX[4]={1,0,-1,0};
int movesY[4]={0,1,0,-1};

bool ordenas(pair<char,int>A,pair<char,int>B){
	if(B.second<A.second)return true;
	if(B.second>A.second)return false;
	if(B.first>A.first) return true;
	return false;
}


bool isValid(int i,int j){
	if(i<0 ||j<0 || i>=m ||j>=n || ma[i][j]!=c||vis[i][j]==true){
		return false;
	}
	return true;
}

void dfs(int x,int y){
	vis[x][y]=true;
	cont++;
	for(int i=0;i<4;i++){
		int nx=x+movesX[i];
		int ny=y+movesY[i];
		if(isValid(nx,ny)){
			dfs(nx,ny);
		}
	}
}

int main(){
	
	cin>>m>>n;
	int vx=1;
	while(m || n){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>ma[i][j];
				vis[i][j]=false;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(!vis[i][j] && ma[i][j]!='.'){
					c=ma[i][j];
					cont=0;
					dfs(i,j);
					save.push_back({c,cont});
					
				}
			}
		}
		cout<<"Problem "<<vx++<<":"<<endl;
		sort(save.begin(),save.end(),ordenas);
		for(int i=0;i<save.size();i++){
			cout<<save[i].first<<' '<<save[i].second<<endl;
			
		}
		save.clear();
		cin>>m>>n;
	}
}

