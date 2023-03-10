#include <bits/stdc++.h>

using namespace std;

bool vis[105][105];
int x[8]={-2,-2,-1,-1,1,1,2,2};
int y[8]={-1,1,2,-2,-2,2,-1,1};

int Kingx[8]={-1,-1,-1,0,0,1,1,1};
int Kingy[8]={0,1,-1,-1,1,1,0,-1};

int bfs(int ix,int iy ,int fimx,int fimy,int a,int b){
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{ix,iy}});
	vis[ix][iy]=true;
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		if(u.second.first==fimx && u.second.second==fimy) return u.first;
		for(int i=0;i<8;i++){
			int nx=u.second.first+Kingx[i],ny=u.second.second+Kingy[i];
			if(nx>=0&& ny>=0 && nx<a && ny<b &&!vis[nx][ny]){
				q.push({u.first+1,{nx,ny}});
				vis[nx][ny]=true;
			}
		}
	}
	return -1;
}

int main(){
	int n,a,b,ix,iy,fx,fy,t;
	char l;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		fx=-1;
		fy=-1;
		for(int j=0;j<a;j++){
			for(int k=0;k<b;k++){
				cin>>l;
				if(l=='A'){
					ix=j;
					iy=k;
				}
				else{
					if(l=='B'){
						fx=j;
						fy=k;
					}
					else{
						if(l=='Z'){
							vis[j][k]=true;
							for(int h=0;h<8;h++){
								int nx=x[h]+j,ny=y[h]+k;
								if(nx>=0 && ny>=0 && nx<a && ny<b ){
									vis[nx][ny]=true;										
								}
							}
						}
					}
				}
			}
		}
		vis[fx][fy]=false;
		t=bfs(ix,iy,fx,fy,a,b);
		if(t==-1 ){
			cout<<"King Peter, you can't go now!";
		}
		else{
			cout<<"Minimal possible length of a trip is "<<t;
		}
		cout<<endl;
		memset(vis,false,sizeof(vis));
	}		 
			
}
