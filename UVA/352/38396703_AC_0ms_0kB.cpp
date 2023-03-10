#include <bits/stdc++.h>

using  namespace std;

bool vis[30][30];
int m[30][30];
int movesx[8]={-1,-1,-1,0,0,1,1,1};
int movesy[8]={0,1,-1,-1,1,1,0,-1};
int n;

bool isValid(int i, int j){
	if(i<0 || j<0 || i>=n || j>=n || vis[i][j]==true || m[i][j]==0){
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
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int c=0;
	while(cin>>n){
		int cont=0;
		vector<pair<int,int>>vi;
		for(int i=0;i<n;i++){
			string str; cin>>str;
			for(int j=0;j<n;j++){
				m[i][j]=str[j]-48;
				if(m[i][j]==1){
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
		cout<<"Image number "<<++c<<" contains "<<cont<<" war eagles."<<endl;
	}	
}