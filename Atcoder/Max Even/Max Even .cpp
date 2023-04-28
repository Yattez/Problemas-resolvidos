#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int const inf=10e6;
vector<int>par;	
vector<int>impar;	


int find(){
	int x=-1;
	int z=par.size()-1;
	if(par.size()>=2)x=max(par[z]+par[z-1],x);
	z=impar.size()-1;
	if(impar.size()>=2)x=max(impar[z]+impar[z-1],x);
	return x;
}
	
	

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	int n,x;
	cin>>n;
	while(n--){
		cin>>x;
		if(x%2==0){
			par.push_back(x);
		}
		else impar.push_back(x);
	}
	sort(par.begin(),par.end());
	sort(impar.begin(),impar.end());
	cout<<find()<<endl;
}
