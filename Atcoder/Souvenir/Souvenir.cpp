#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;

const int INF=-(int)1e9;
const int voo=1e9;
int n;
vector<vector<pair<int,int>>>d(1000,vector<pair<int,int>>(1000));
void floyd(){	
	for (int k =0;k<n;k++) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if((d[i][k].f+d[k][j].f<d[i][j].f)){
					d[i][j].f=d[i][k].f+d[k][j].f;
					d[i][j].s=d[i][k].s+d[k][j].s;
				}
				else if(d[i][k].f+d[k][j].f==d[i][j].f) d[i][j].s = max(d[i][j].s, d[i][k].s + d[k][j].s); 
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int m,x,y;
	char c;
	cin>>n;
	vector<int>preco(n);
	for(int i=0;i<n;i++){
		cin>>preco[i];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>c;
			if(c=='Y'){
				d[i][j]={1,preco[i]}; 	
			}
			else{
				d[i][j]={voo,INF};
			}
		}
	}
	floyd();
	cin>>m;
	for(int i=0;i<m;i++) {
		cin>>x>>y;
		if(d[x-1][y-1].f!=voo)cout<<d[x-1][y-1].f<<" "<<d[x-1][y-1].s+preco[y-1]<<endl;
		else cout<<"Impossible"<<endl;
	}
}
