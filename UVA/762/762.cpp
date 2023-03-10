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
	int n;
	string x,y,a,b;
	bool hp=false;
	while(cin>>n){
		if(hp==false){
			hp=true;
		}
		else{
			cout<<endl;
		}
		bool fim=false;
		for(int i=0;i<n;i++){
			cin>>x;
			cin>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			vis[x]=false;
			vis[y]=false;
		}
		cin>>a>>b;
		bfs(a);
		for(auto it:pai){
			if(it.first==b){
				fim=true;
			}
		}
		pai[a]=a;
		string x;
		if(fim==true){
			findpath(a,b);
			x=ordem.top();
			ordem.pop();
			while(!ordem.empty()){;
				cout<<x;
				cout<<" "<<ordem.top()<<endl;
				x=ordem.top();
				ordem.pop();
			}
		}
		else{
			cout<<"No route"<<endl;
		}
		adj.clear();
		vis.clear();
		pai.clear();
	}	
}
