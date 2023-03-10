#include <bits/stdc++.h>

using namespace std;

const int inf=1000000;
vector<pair<int,int>>adj[120];
int vd[120];

void dijikstra(int ori){
    memset(vd,inf,sizeof(vd));
    vd[ori]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,ori});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        if(u.first>vd[u.second]) continue;
        for(auto v: adj[u.second]){
            if(vd[v.second]>v.first+u.first){
                pq.push({v.first+u.first,v.second});
                vd[v.second]=v.first+u.first;
            }
        }
    }
}

int main(){
    //~ freopen("input.txt","r",stdin);
    //~ freopen("output.txt","w",stdout); 
	int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
        int m, ext,t,c;
        cin>>m>>ext>>t;
        cin>>c;
        for(int j=0;j<c;j++){
            int x,y,d;
            cin>>x>>y>>d;
            adj[x].push_back({d,y});
		}
		
        int s=0;
        for(int k=1;k<=m;k++){
			dijikstra(k);
			if(vd[ext]<=t){
				s++;
			}
		}
       cout<< s<<endl;
       if(i<n-1){
            cout<<endl;
        }
       for(int j=0;j<120;j++){
		   adj[j].clear();
	   }
    }

}
