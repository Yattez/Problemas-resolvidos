#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
int f91(int n){
	if(n<=100)return f91(f91(n+11));
	return n-10;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);   
	int n;
	cin>>n;
	while(n!=0){
		cout<<"f91("<<n<<") = "<<f91(n)<<endl;
		cin>>n;
	}
	
}
