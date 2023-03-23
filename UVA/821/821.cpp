#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;

const int INF=(int)1e9;
int n;
vector<vector<int>>d(1000,vector<int>(1000,INF));

void makeset(){
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			d[i][j]=INF;
		}
	}
}

void floyd(){	
	for(int k =0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if((d[i][k]+d[k][j]<d[i][j])) d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int x,y;
	int cont=0;
	cin>>x>>y;
	while(x || y){
		n=-1;
		double soma=0;
		int h=0;
		queue<pair<int,int>>q;
		while(x|| y){
			q.push({x-1,y-1});
			d[x-1][y-1]=1;
			if(n<x){
				n=x;
			}
			if(n<y){
				n=y;
			}
			cin>>x>>y;
		}
		floyd();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(d[i][j]!=INF && i!=j){
					soma+=d[i][j];
					h++;
				}
				
			}
		}
		makeset();
		cout<<fixed<<setprecision(3);
		cout<<"Case "<<++cont<<": average length between pages = "<<soma/h<<" clicks"<<endl;
		cin>>x>>y;
	}
}
