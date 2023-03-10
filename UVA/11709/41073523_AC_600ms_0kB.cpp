#include <bits/stdc++.h>

using namespace std;


int n,m;
int r=0;
map<string,vector<string>>adj;
map<string,vector<string>>rev;

map<string,bool> vis1;
map<string,bool> vis2;
stack<string>st;

void DFS(string node){
    vis1[node]=true;
    for(auto u:adj[node]){
		if(vis1[u]!=true){
            DFS(u);
        }
    }
    st.push(node);
}

void DFS2(string node){
    vis2[node]=true;
    for(auto u:rev[node]){
		if(vis2[u]!=true){
			DFS2(u);
       }
    }

}
void findcss(){
	r=0;
	for(auto it:adj){
		string h=it.first;
		if(!vis1[h]){
			DFS(h);
		}
	}
    while(!st.empty()){
        auto k=st.top();
        st.pop();
        if(vis2[k]!=true){
			r++;
            DFS2(k);
        }
    }
    cout<<r<<endl;
}
	
int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
    cin>>n>>m;
    while(n!=0 || m!=0){
		string x,y;
		cin.ignore();
		while(n--){
			getline(cin,x);
			adj[x].push_back("");
			adj[x].clear();
		}
		
		while(m--){
			getline(cin,x);
			getline(cin,y);
			adj[x].push_back(y);
			rev[y].push_back(x);
		}
		findcss();
		cin>>n>>m;
		vis1.clear();
		vis2.clear();
		adj.clear();
		rev.clear();
	}
}
