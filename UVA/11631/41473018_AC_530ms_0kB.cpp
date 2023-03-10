#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int n, e, a, b, d;
	vector<pair<int,pair<int,int>>>vec;
	cin>>n>>e;
	while(n || e){
		vector<Edge> edges;
		vector<int> tree_id(n);
		vector<Edge> result;
		
		for (int i = 0; i < n; i++)tree_id[i] = i;
		
		for(int i=0; i<e; i++){
			cin>>a>>b>>d;
		
			Edge aux;
			aux.u=a;
			aux.v=b;
			aux.w=d;
			edges.push_back(aux);
		}
		sort(edges.begin(), edges.end());
		int cost = 0;
		for (Edge e : edges) {
			if (tree_id[e.u] != tree_id[e.v]) {
				
				result.push_back(e);

				int old_id = tree_id[e.u], new_id = tree_id[e.v];
				for (int i = 0; i < n; i++) {
					if (tree_id[i] == old_id)
						tree_id[i] = new_id;
				}
			}
			else{
				cost += e.w;
			}
		}
		cout<<cost;
		cout<<endl;
		cin>>n>>e;
	}
}
