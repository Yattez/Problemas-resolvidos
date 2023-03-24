#include <bits/stdc++.h>
#define f first
#define s second
#define int long long


using namespace std;

vector<int>v(5);

bool res=false;
void back(int k,int sum){
	if(k==5){
		if(sum==23)
		{
			res=true;
		}
		return ;
	}
	for(int i=0;i<3;i++){
		if(i==0)back(k+1,sum+v[k]);
		if(i==1)back(k+1,sum-v[k]);
		if(i==2)back(k+1,sum*v[k]);
	}
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	for(int i=0;i<5;i++){
		cin>>v[i];
	}
	while(v[0] ||v[1] ||v[2] || v[3] || v[4]){	
		sort(v.begin(),v.end());
		res=false;
		back(1,v[0]);
		while(next_permutation(v.begin(),v.end()) && !res){
			back(1,v[0]);
		}
		if(!res)cout<<"Impossible"<<endl;
		else cout<<"Possible"<<endl;
		for(int i=0;i<5;i++){
			cin>>v[i];
		}
	}
}
