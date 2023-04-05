#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;



const int inf=LLONG_MIN;
vector<int>adj[10000];
int vis[10000];
int peso[10000];
int dist[10000];
stack<int>Stack;
int s,n,e;



void makeset(){
	for (int i = 0; i < 10000; i++){
		vis[i] = false;
		adj[i].clear();
		peso[i]=0;	
	}
	while(!Stack.empty()){
		Stack.pop();
	}
}

void topologicalSortUtil(int v)
{
	vis[v] = true;
	for (auto u: adj[v]) {
		if(!vis[u])
			topologicalSortUtil(u);
	}
	Stack.push(v);
}


void DAG(int s){
	for (int i = 0; i < n; i++){
		if (vis[i] == false){
			topologicalSortUtil(i);
		}
	}
	stack<int> stck=Stack;
	int maior=LLONG_MIN;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++)dist[j]=inf;
		dist[i]=peso[i];
		Stack=stck;
		while (!Stack.empty()) {
			int v = Stack.top();
			Stack.pop();
			if (dist[v] != inf) {
				for (auto u: adj[v]) {
					if (dist[u] < dist[v] + peso[u]){
						dist[u] = dist[v] + peso[u];
					}
				}
			}
		}
		for (int k = 0; k < n; k++){
			if(dist[k]>maior)maior=dist[k];
		}
	}
	cout<<maior<<endl;
		
}	

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int t,p,x;
	cin>>t;
	string str, lix,c;
	cin.ignore();
	n=0;
	getline(cin,str);
	for(int k=0;k<t;k++){
		makeset();
		n=-1;
		if(k!=0 )cout<<endl;
		getline(cin,str);
		while(str!="\0"){
			vector<string>ad;
			stringstream ss(str);
			while(ss>>str){
				ad.push_back(str);
			}
			if(ad.size()>0){
				x=ad[0][0]-'A';
				if(n<x+1)n=x+1;
			}
			if(ad.size()>1){
				p=stoi(ad[1]);
				peso[x]=p;
			}
			if(ad.size()>2){
				string ch=ad[2];
				for(int j=0;j<(int)ch.size();j++){
					int h=ch[j]-'A';
					adj[h].push_back(x);
				}
			}
			n++;
			getline(cin,str);
		}
		DAG(s);
	}
}
