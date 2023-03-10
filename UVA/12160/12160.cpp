#include <bits/stdc++.h>


#define saida freopen("output.txt","w",stdout);
#define entrada freopen("input.txt","r",stdin);

using namespace std;

int vis[10005];
vector<int>botao;

int bfs(int origem,int destino){
	memset(vis,false,sizeof(vis));
	queue<pair<int,int>> q;
	q.push({0,origem});
	vis[origem]=true;
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		if(u.second==destino) return u.first;
		int h=botao.size();
		for(int i=0;i<h;i++){
			int x=(botao[i]+u.second)%10000;
			if(!vis[x]){
				vis[x]=true;
				q.push({u.first+1,x});
			}
		}
	}
	return -1;
}

int main(){
	//~ entrada;
	//~ saida;
	int x,y,z,a,cont=1,b;
	cin>>x>>y>>z;
	while(x || y ||z){
		for(int i=0;i<z;i++){
			cin>>a;
			botao.push_back(a);
		}
		cout<<"Case "<<cont<<": ";
		b=bfs(x,y);
		if(b==-1){
			cout<<"Permanently Locked"<<endl;
		}
		else{
			cout<<b<<endl;
		}
		botao.clear();
		cin>>x>>y>>z;
		cont++;
	}
}
