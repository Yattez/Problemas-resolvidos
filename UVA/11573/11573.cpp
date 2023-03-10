#include <bits/stdc++.h>

using namespace std;

int Kingx[8]={-1,-1,0,1,1,1,0,-1};
int Kingy[8]={0,1,1,1,0,-1,-1,-1};
char dire[8]={'0','1','2','3','4','5','6','7'};

int a,b;

char m[1010][1010];
int dist[1010][1010];


bool isValid(int nx,int ny){
	if(nx>=0 && ny>=0 && nx<a && ny<b ){
		return true;
	}
	return false;
}

void bfs(int ix,int iy){
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	pq.push({0,{ix,iy}});
	dist[ix][iy]=0;
	while(!pq.empty()){
		auto u=pq.top();
		pq.pop();
		if(u.first>dist[u.second.first][u.second.second]) continue;
		for(int i=0;i<8;i++){
			int nx=u.second.first+Kingx[i],ny=u.second.second+Kingy[i];
			if(m[u.second.first][u.second.second]==dire[i]){
				if(isValid(nx,ny) && dist[nx][ny]>dist[u.second.first][u.second.second] ){
					dist[nx][ny]=dist[u.second.first][u.second.second];
					pq.push({dist[nx][ny],{nx,ny}});
				}
			}
			else{
				if(isValid(nx,ny) && dist[nx][ny]>dist[u.second.first][u.second.second]+1 ){
					dist[nx][ny]=dist[u.second.first][u.second.second]+1;
					pq.push({dist[nx][ny],{nx,ny}});
				}
			}
		}
	}
}
	

int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>m[i][j];
		}
	}
	int n,ix,iy,fx,fy;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int k=0;k<a;k++){
			for(int j=0;j<b;j++){
				dist[k][j]=999999;
			}
		}
		cin>>ix>>iy>>fx>>fy;
		bfs(ix-1,iy-1);
		cout<<dist[fx-1][fy-1]<<endl;
	}
}
