#include <bits/stdc++.h>

using namespace std;


int n,m,x,y,z;
priority_queue <int, vector<int>, greater<int>>adj[2020];
priority_queue <int, vector<int>, greater<int>>rev[2020];

bool vis1[2020];
bool vis2[2020];
stack<int>st;

void DFS(int node){
    vis1[node]=true;
	while(!adj[node].empty()){
		int v=adj[node].top();
		adj[node].pop();
		if(!vis1[v]){
            DFS(v);
        }
    }
    st.push(node);
}

void DFS2(int node){
	//~ cout<<node<<endl;
    vis2[node]=true;
	while(!rev[node].empty()){
		int v=rev[node].top();
		rev[node].pop();
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
	if(r==1){
		cout<<1<<endl;
	}
	else{
		cout<<0<<endl;
	}
}


int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>m;
	while(n!=0 || m!=0){
		for(int j=0;j<n;j++){
			vis1[j]=false;
			vis2[j]=false;
			for(int h=0;h<int(adj[j].size());h++){
				adj[j].pop();
			}
			for(int h=0;h<int(rev[j].size());h++){
				rev[j].pop();
			}
		}
		while(m--){
			cin>>x>>y>>z;
			if(z==1){
				adj[x-1].push(y-1);
				rev[y-1].push(x-1);
			}
			else{
				adj[x-1].push(y-1);
				rev[y-1].push(x-1);
				adj[y-1].push(x-1);
				rev[x-1].push(y-1);
			}
		}
		findcss();		
		cin>>n>>m;
	}			
}
