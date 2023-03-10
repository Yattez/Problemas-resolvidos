#include <bits/stdc++.h>

using namespace std;

const int inf=1000000;
vector<pair<int,int>>adj[20010];
int vd[20010];
bool cc;

int dijikstra(int ori,int fim){
    memset(vd,inf,sizeof(vd));
    vd[ori]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,ori});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        if(u.first>vd[u.second]) continue;
        for(auto v: adj[u.second]){
            if(v.second==fim){
                    cc=true;
            }
            if(vd[v.second]>v.first+u.first){
                
                pq.push({v.first+u.first,v.second});
                vd[v.second]=v.first+u.first;
            }
        }
    }
    return vd[fim];
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout); 
    ios_base::sync_with_stdio(false);
	int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cc=false;
        int s,c,o,f;
        cin>>s>>c>>o>>f;
        int a,b,d;
        for(int j=0;j<c;j++){
            cin>>a>>b>>d;
            adj[a].push_back({d,b});
            adj[b].push_back({d,a});
        }
        int h=dijikstra(o,f);
        if(c==0 || cc==false){
            cout<<"Case #"<<i+1<<": unreachable"<<endl;
        }
        else{
         cout<<"Case #"<<i+1<<": "<<h<<endl;
        }
        for(int j=0;j<20010;j++){
           adj[j].clear();
        }
    }
}