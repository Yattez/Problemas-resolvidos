#include <bits/stdc++.h>

using namespace std;

map<string,vector<string>>adj;
map<string,bool>vis;
map<string,string>pai;
stack<string>ordem;

void findpath(string a,string b){
	ordem.push(b);
	if(pai[b]==a){
		ordem.push(a);
		return;
	}
	findpath(a,pai[b]);
}
void bfs(string origem){
	queue<string>q;
	q.push(origem);
	vis[origem]=true;
	while(!q.empty()){
		string u=q.front();
		q.pop();
		for(auto v:adj[u]){
			if(!vis[v]){
				pai[v]=u;
				q.push(v);
				vis[v]=true;
			}
		}
	}
}


int main(){	
	int n,q,w;
	string x,y,a,b;
	bool hp=false;
	cin>>n;
	for(int k=0;k<n;k++){
		cin>>q>>w;
		if(hp==false){
			hp=true;
		}
		else{
			cout<<endl;
		}
		for(int i=0;i<q;i++){
			cin>>x;
			cin>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			vis[x]=false;
			vis[y]=false;
		}
		for(int j=0;j<w;j++){
			cin>>a>>b;
			bfs(a);
			pai[a]=a;
			string x;
			findpath(a,b);
			while(!ordem.empty()){;
				cout<<ordem.top()[0];
				ordem.pop();
			}
			vis.clear();
			pai.clear();
			cout<<endl;
		}
		adj.clear();
	}	
}
