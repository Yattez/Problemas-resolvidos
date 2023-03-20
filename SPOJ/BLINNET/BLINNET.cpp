#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;


int const inf=1000000;
vector<pair<int,pair<int,int>>>adj;
vector<int>pai(1000000),r(1000000);
int caminho=0;



void makeSet(int n){
	adj.clear();
	caminho=0;
    for(int i=0; i<=n; i++){
        pai[i]=i;
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
            caminho+=peso;
        }  
    }
}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int t,n,e,x,y;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		makeSet(n);
		
		for(int i=1;i<=n;i++){
			cin>>s>>e;
			for(int j=0;j<e;j++){
				cin>>x>>y;
				adj.push_back({y,{i,x}});
			}
		}
		sort(adj.begin(), adj.end());
		kruskal(adj.size());
		cout<<caminho<<endl;
	}	
}
