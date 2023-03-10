#include <bits/stdc++.h>

using namespace std;

stack<int>t;
vector<int>adj[30];

bool vis[30];


void dfs(int u){
	vis[u]=true;
	for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v); 
           
        }
    }
    t.push(u);
}

int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	string x;
	vector<string>palavra;
	while(cin>>x){
		while(x!="#"){
			palavra.push_back(x);
			cin>>x;
		}
		for(int i=0,j=i+1;i<palavra.size()-1;i++,j++){
			for(int k=0;k<palavra[i].size();k++){
				if(k<=palavra[i].size() && k<=palavra[j].size()){
					if(palavra[i][k]!=palavra[j][k]){
						adj[palavra[i][k]-65].push_back(palavra[j][k]-65);
						k=palavra[i].size()+10;
						
					}
				}
				else{
					k=palavra[i].size()+10;
				}
			}
		}
		for(int i=0;i<palavra.size();i++){
			for(int j=0;j<palavra[i].size();j++){
				if(!vis[palavra[i][j]-65]){
					dfs(palavra[i][j]-65);
				}
			}
		}
			
		while(!t.empty()){
			string h;
			h=t.top()+'A';
			cout<<h;
			t.pop();
		}
		cout<<endl;
		palavra.clear();
		memset(vis,false,sizeof(vis));
		for(int i=0;i<30;i++){
			adj[i].clear();
		}
	}
}
