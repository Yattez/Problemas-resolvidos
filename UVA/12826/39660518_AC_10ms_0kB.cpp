#include <bits/stdc++.h>

using namespace std;

bool vis[10][10];

int Kingx[8]={-1,-1,-1,0,0,1,1,1};
int Kingy[8]={0,1,-1,-1,1,1,0,-1};

bool isValid(int nx,int ny){
	if(nx>=0&& ny>=0 && nx<8 && ny<8 &&!vis[nx][ny]){
		return true;
	}
	return false;
}

int bfs(int ix,int iy,int fx,int fy){
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{ix,iy}});
	vis[ix][iy]=true;
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		if(u.second.first==fx && u.second.second==fy) return u.first;
		for(int i=0;i<8;i++){
			int nx=u.second.first+Kingx[i],ny=u.second.second+Kingy[i];
			if(isValid(nx,ny)){
				q.push({u.first+1,{nx,ny}});
				vis[nx][ny]=true;
			}
		}
	}
	return 0;
}

int main(){
	int ix,iy,fx,fy,cx,cy;
	int cont=0;
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	while(cin>>ix>>iy>>fx>>fy>>cx>>cy){
		cont++;
		memset(vis,false,sizeof(vis));
		vis[cx-1][cy-1]=true;
		cout<<"Case "<<cont<<": "<<bfs(ix-1,iy-1,fx-1,fy-1)<<endl;		
	}
	
	
	
	
}
