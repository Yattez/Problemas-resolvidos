#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int const inf=10e7;
vector<pair<int,int>>v;



signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	int t,x,y;
	cin>>t;
	while(t--){
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());
	int in=v[0].f,fim=v[0].s;
	for(int i=1;i<(int)v.size();i++){
		if(v[i].f<=fim){
			if(v[i].s>fim)fim=v[i].s;
		}
		else{
			cout<<in<<" "<<fim<<endl;
			in=v[i].f;
			fim=v[i].s;
		}
	}
	cout<<in<<" "<<fim<<endl;
}
