#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

bool ordenas (string a,string b){
    if(a<b)return true;
    return false;
}

bool isSub(string a,string b){
	bool c=true;
	for(int i=0;i<a.size() && i<b.size()&& c;i++){
		if(a[i]!=b[i]){
			c=false;
		}
	}
	return c;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int n,t;
	string x;
	
	cin>>t;
	while(t--){
		cin>>n;
		vector<string>v;
		while(n--){
			cin>>x;
			v.push_back(x);
		}
		if(v.size()!=1){
			bool pre=false;
			sort(v.begin(),v.end(),ordenas);
			for(int i=0;i<v.size()&& !pre;i++){
				for(int j=i+1;j<v.size()&& !pre;j++){
					if(v[i][0]!=v[j][0]){
						j=v.size();
					}
					else if(isSub(v[i],v[j]))pre=true;
				}
			}
			if(!pre)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
}
