#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>adj(30);
vector<bool>vis(30);

void dfs(int u){
	vis[u]=true;
	for(auto v :adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}

int main(){
	int x,a,b,c,cont;
	string ex;
	cin>>x;
	cin.ignore();
	getline(cin,ex);
	for(int i=0;i<x;i++){
		if(i>0){
			cout<<endl;
		}
		getline(cin,ex);
		c=ex[0]-'A';
		cont=0;
		getline(cin,ex);
		while(ex!="\0"){
			a=ex[0]-'A';
			b=ex[1]-'A';
			adj[a].push_back(b);
			adj[b].push_back(a);
			getline(cin,ex);
		}
		for(int j=0;j<=c;j++){
			if(!vis[j]){
				dfs(j);
				cont++;
			}
		}
		cout<<cont<<endl;
		for(int j=0;j<30;j++){
			adj[j].clear();
			vis[j]=false;
		}
	}
}
