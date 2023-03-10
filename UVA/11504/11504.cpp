#include <bits/stdc++.h>

using namespace std;


int a,n,m,x,y;
vector<int>adj[100010];
vector<int>rev[100010];

bool vis1[100010];
bool vis2[100010];
stack<int>st;

void DFS(int node){
    vis1[node]=true;
    for(auto v :adj[node]){
		if(!vis1[v]){
            DFS(v);
        }
    }
    st.push(node);
}

void DFS2(int node){
    vis2[node]=true;
	for(auto v :adj[node]){
		if(!vis2[v]){
            DFS2(v);
       }
    }

}
void findcss(){
	for(int h=0;h<n;h++){
		if(!vis1[h]){
			DFS(h);
		}
	}
    int r=0;
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
	cin>>a;
	for(int i=0;i<a;i++){
		for(int j=0;j<n;j++){
			vis1[j]=false;
			vis2[j]=false;
			adj[j].clear();
			rev[j].clear();
		}
		cin>>n>>m;
		while(m--){
			cin>>x>>y;
			adj[x-1].push_back(y-1);
			rev[y-1].push_back(x-1);
		}
		findcss();
	}
			
}


