#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int pai[250010];

bool ordenas(pair<int,pair<int,int>> A, pair<int,pair<int,int>> B){
	if(A.first>B.first) return true;
	return false;
}

int findPath(int x){
	if(pai[x]==x) return x;
	return pai[x] = findPath(pai[x]);
}

int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int n, e, a, b, v;
	vector<pair<int,pair<int,int>>>vec;
	cin>>n>>e;
	while(n || e){
		for(int i=0; i<n; i++)pai[i]=i;
		priority_queue<int,vector<int>,greater<int>> pq;
		vec.clear();
		for(int i=0; i<e; i++){
			cin>>a>>b>>v;
			vec.push_back({v,{a, b}});
		}
		sort(vec.begin(), vec.end());
		for(int i=0; i<e; i++){
			
			int dist = vec[i].f;
			int u = vec[i].s.f;
			int v = vec[i].s.s;
			
			int Pv = findPath(v);
			int Pu = findPath(u);
			
			//verificar se os dois nodes tem o mesmo pai
			if(Pu != Pv){
				//nao fazer desse jeito ruim, pesquisa "path compression" ai
				pai[Pu] = Pv;
			}
			else{
				pq.push(dist);
			}	
		}

		if(pq.empty()){
			cout<<"forest"<<endl;
		}
		else{	
			cout<<pq.top();
			pq.pop();
			while(!pq.empty()){
				cout<<" "<<pq.top();
				pq.pop();
			}
			cout<<endl;
		}
		cin>>n>>e;
	}
}
