#include <bits/stdc++.h>

using namespace std;

const long long int inf=1000000;
int x,y;
long long int vd[1005][1005];
int m[1005][1005];

int movesx[4]{0,1,-1,0};
int movesy[4]{1,0,0,-1};


int dijikstra(){
    memset(vd,inf,sizeof(vd));
    vd[0][0]=m[0][0];
    priority_queue<pair<long long int,pair<int,int>>,vector<pair<long long int,pair<int,int>>>,greater<pair<long long int,pair<int,int>>>>pq;
    pq.push({vd[0][0],{0,0}});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
		if(u.first>vd[u.second.first][u.second.second]) continue;
        for(int i=0;i<4;i++){
			int nx=u.second.first+movesx[i];
			int ny=u.second.second+movesy[i]; 
			
            if(nx>=0 && ny>=0 && nx<x && ny<y && vd[nx][ny]>m[nx][ny]+u.first){
				
				pq.push({m[nx][ny]+u.first,{nx,ny}});
                vd[nx][ny]=m[nx][ny]+u.first;
            }
        }
    }
    return vd[x-1][y-1];
}


int main(){
	//~ freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	while(n--){
		cin>>x>>y;
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				cin>>m[i][j];
			}
		}
		cout<<dijikstra()<<endl;
	}
}
