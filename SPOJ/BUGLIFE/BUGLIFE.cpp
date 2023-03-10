#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>adjlist;

bool bipartido(int n){
	vector<bool>vis(n,0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			queue<int>q;
			q.push(i);
			vector<bool>genero(n,i);
			vis[i]=true;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:adjlist[u]){
					if(!vis[v]){
						vis[v]=true;
						genero[v]=genero[u]^1;
						q.push(v);
					}
					else if(genero[u]==genero[v]){
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	int n,a,v,x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v>>a;
		adjlist = vector<vector<int>> (v);
		for(int j=0;j<a;j++){
			cin>>x>>y;
			x--;
			y--;
			adjlist[x].push_back(y);
			adjlist[y].push_back(x);
		}
		cout<<"Scenario #"<<i<<':'<<endl;
		if(bipartido(v)){
			cout<<"No suspicious bugs found!"<<endl;
		}
		else{
			cout<<"Suspicious bugs found!"<<endl;
		}
	}
}
