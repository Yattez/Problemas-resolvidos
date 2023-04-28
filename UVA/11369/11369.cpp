#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int const inf=10e7;
priority_queue<int>v;

int off(){
	int d=0;
	while(!v.empty()){
		for(int i=0;i<2 && !v.empty();i++){
			v.pop();
		}
		if(!v.empty()){
			 d+=v.top();
			 v.pop();
		 }
	 }
	 return d;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int t,n,x;
	cin>>t;
	while(t--){
		cin>>n;
		while(n--){
			cin>>x;
			v.push(x);
		}
		cout<<off()<<endl;
	}
}
