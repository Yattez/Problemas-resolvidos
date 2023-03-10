#include <bits/stdc++.h>


#define saida freopen("output.txt","w",stdout);
#define entrada freopen("input.txt","r",stdin);

using namespace std;

int movesX[4]={-1,0,1,0};
int movesY[4]={0,1,0,-1};

bool vis[1000][1000];
int dist[1000][1000];
pair<int,int> tamanho;


bool isValid(int i, int j){
	if(i<0 or j<0 or i>=tamanho.first or j>=tamanho.second or vis[i][j] == true or dist[i][j] == -1){
		return false;
	}
	return true;
}


int bfs(pair<int,int> origem,pair<int,int> destino){
	queue<pair<int,int>>q;
	q.push(origem);
	vis[origem.first][origem.second]=true;
	dist[origem.first][origem.second]=0;
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=u.first+movesX[i];
			int ny=u.second+movesY[i];
			if(isValid(nx,ny)){
				vis[nx][ny]=true;
				dist[nx][ny]=dist[u.first][u.second]+1;
				q.push({nx,ny});
			}
		}
	}
	return dist[destino.first][destino.second];
}

int main(){	
	int a,b,n,x,z,y,in1,in2,fim1,fim2;
	cin>>a>>b;
	while(a || b){
		tamanho={a,b};
		for(int i=0;i<a;i++){
			for(int k=0;k<b;k++){
				vis[i][k]=false;
				dist[i][k]=0;
			}
		}
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>x>>y;
			for(int j=0;j<y;j++){
				cin>>z;
				vis[x][z]=true;
				dist[x][z]=-1;
			}
		}
		cin>>in1>>in2;
		cin>>fim1>>fim2;
		cout<<bfs({in1,in2},{fim1,fim2})<<endl;
		cin>>a>>b;
	}
}
