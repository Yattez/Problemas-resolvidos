#include <bits/stdc++.h>
#define f first
#define s second
#define int long long

using namespace std;

const int inf=1e9;
const string c="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
int n,m,q;
map<char,int>tra;
void traducao(){
	char x='A';
	int y=0;
	for(int i=0;i<26;i++){
		x='A'+i;
		tra[x]=y+i;		
	}
}
	
vector<vector<pair<int,string>>>d(1000,vector<pair<int,string>>(1000));
void makeset(){
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			d[i][j].f=inf;
			d[i][j].s=c;
		}
	}
}

void floyd(){	
	for(int k =0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if((d[i][k].f+d[k][j].f<d[i][j].f)){
					 d[i][j].f=d[i][k].f+d[k][j].f;
					 d[i][j].s=d[i][k].s+" "+d[k][j].s;
				 }
				else if(d[i][k].f+d[k][j].f==d[i][j].f){
					if(d[i][k].s.size()+d[k][j].s.size()<d[i][j].s.size()){
						d[i][j].s=d[i][k].s+" "+d[k][j].s;
					}
					if(d[i][k].s+d[k][j].s<d[i][j].s){
						d[i][j].s=d[i][k].s+" "+d[k][j].s;
					}
				}
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>m;
	int  x,y,z;
	char  a,b;
	traducao();
	makeset();
	for(int i=0;i<m;i++){
		cin>>a>>b>>z;
		x=tra[a];
		y=tra[b];
		d[x][y].f=z;
		d[y][x].f=z;
		d[x][y].s=a;
		d[y][x].s=b;
	}
	floyd();
	cin>>q;
	while(q--){
		cin>>a>>b;
		x=tra[a];
		y=tra[b];
		cout<<d[x][y].s+" "+b<<endl;
	}
}
