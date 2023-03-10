#include <bits/stdc++.h>

using  namespace std;

bool vis[120][120];
int m[120][120];
int movesx[8]={-1,-1,-1,0,0,1,1,1};
int movesy[8]={0,1,-1,-1,1,1,0,-1};
int n,ma;

bool isValid(int i, int j){
	if(i<0 || j<0 || i>=n || j>=ma || vis[i][j]==true || m[i][j]=='*'){
		return false;
	}
	return true;
}

void ff(int x,int y){
	vis[x][y]=true;
	for(int i=0;i<8;i++){
		int nx=movesx[i]+x;
		int ny=movesy[i]+y;
		if(isValid(nx,ny)){
			ff(nx,ny);
		}
	}
}

int main(){
	cin>>n>>ma;
	char x;
	while(n!=0 && m!=0){
		int cont=0;
		vector<pair<int,int>>vi;
		for(int i=0;i<n;i++){
			for(int j=0;j<ma;j++){
				cin>>x;
				m[i][j]=x;
				if(m[i][j]=='@'){
					vi.push_back({i,j});
				}
				vis[i][j]=false;
			}
		}
		for(int i=0;i<vi.size();i++){
			if(vis[vi[i].first][vi[i].second]==false){
				cont++;
				ff(vi[i].first,vi[i].second);
			}
		}
		cout<<cont<<endl;
		cin>>n>>ma;
	}	
}