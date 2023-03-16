#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int const inf=1000000;
vector<pair<int,pair<int,int>>>adj;
vector<pair<int,int>>result[1000000];
vector<int>pai(1000000),r(1000000);
bool vis[1000000];
int m=0;
bool cc=false;


void dfs( int origem, int fim,int peso){
	vis[origem]=true;
	if(origem==fim){
		cc=true;
		if(m < peso) m = peso;
		return;
	}
	for(auto v:result[origem]){
		if(!vis[v.s]){
			dfs(v.s,fim,v.f);
			if(cc==true){
				if(m < peso) m = peso;
				return;
			}
		}
	}
}


void makeSet(int n){
	adj.clear();
    for(int i=0; i<=n; i++){
        pai[i]=i;
        result[i].clear();
        r[i]=1;
    }
}



int find(int x){
    if(pai[x]==x){
        return x;
    }
    return pai[x]=find(pai[x]);
}


bool sameSet(int x, int y){
    return find(x)==find(y);
}



void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(r[x]>r[y]){
        pai[y]=x;
        r[x]+=r[y];
    }
    else{
        pai[x]=y;
        r[y]+=r[x];
    }
}



void kruskal(int n){
    for(int i=0; i<n; i++){
        int peso=adj[i].f;
        int a=adj[i].s.f,b=adj[i].s.s;
       
        if(!sameSet(a,b)){
            unite(a,b);
            result[a].push_back({peso,b});
            result[b].push_back({peso,a});
        }  
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int c,q,s,k=1;
	cin>>c>>s>>q;
	while(c || s || q){
		if(k!=1) cout<<endl;
		cout<<"Case #"<<k++<<endl;
		int x,y,z;
		makeSet(c);
		 for(int i=0; i<s; i++){
            cin>>x>>y>>z;
            adj.push_back({z,{x,y}});
        }
		sort(adj.begin(), adj.end());
		kruskal(adj.size());
		for(int i=0;i<q;i++){
			cin>>x>>y;
			cc=false;
			m=0;
			memset(vis,false,sizeof(vis));
			dfs(x,y,0);
			
			if(cc==false){
				cout<<"no path"<<endl;
			}
			else{
				cout<<m<<endl;
			}
		}
		cin>>c>>s>>q;		
	}
}
