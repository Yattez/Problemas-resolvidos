#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int n;
vector<pair<int,int>>drug;

int pd[500000][2];


int happy(int i,bool turn){	
	if(i==(int)drug.size())return 0;
	if(pd[i][turn]!=-1)return pd[i][turn];
	int x=0,y=0,z=0;
	if(drug[i].f==1 && turn) x=happy(i+1,false)+drug[i].s;
	if(drug[i].f==0) y=happy(i+1,true)+drug[i].s;
	z=happy(i+1,turn);
	return pd[i][turn]=max({x,y,z});
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	memset(pd,-1,sizeof(pd));
	cin>>n;
	for(int i=0;i<n ;i++){
		int x,y;
		cin>>x>>y;
		drug.push_back({x,y});
	}
	cout<<happy(0,true)<<endl;
}
