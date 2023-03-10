#include <bits/stdc++.h>

using namespace std;
int INF=100000000;
int capacity[61][61];
vector<int> adj[61];
map<string,int>tra;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
		//cout<<cur<<" "<<flow<<endl;
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, int n) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent), new_flow) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
int main(){
	tra["S"]=55;
	tra["M"]=54;
	tra["XS"]=53;
	tra["L"]=52;
	tra["XL"]=51;
	tra["XXL"]=50;
	int x,m,n;
	string t1,t2;
	cin>>x;
	for(int i=0;i<x;i++){
		cin>>m>>n;
		capacity[55][60]=m/6;
		capacity[54][60]=m/6;
		capacity[53][60]=m/6;
		capacity[52][60]=m/6;
		capacity[51][60]=m/6;
		capacity[50][60]=m/6;
		adj[55].push_back(60);
		adj[54].push_back(60);
		adj[53].push_back(60);
		adj[52].push_back(60);
		adj[51].push_back(60);
		adj[50].push_back(60);
		adj[60].push_back(50);
		adj[60].push_back(51);
		adj[60].push_back(52);
		adj[60].push_back(53);
		adj[60].push_back(54);
		adj[60].push_back(55);
		for(int j=1;j<=n;j++){
			cin>>t1>>t2;
			capacity[0][j]=1;
			capacity[j][tra[t1]]=1;
			capacity[j][tra[t2]]=1;
			
			adj[0].push_back(j);
			adj[j].push_back(0);
			
			adj[j].push_back(tra[t1]);
			adj[tra[t1]].push_back(j);
			
			adj[j].push_back(tra[t2]);
			adj[tra[t2]].push_back(j);
		}
		if(maxflow(0,60,61)==n){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		for(int j=0;j<61;j++){
			for(int k=0;k<61;k++){
				capacity[j][k]=0;
			}
		}
		for(int j=0;j<61;j++){
			adj[j].clear();
		}
	}			
}
