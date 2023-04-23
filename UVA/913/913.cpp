#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);   
	
	int n;
	 while (cin >> n){
        n=n/2+1;
        n=n*n;
        cout<<6*n-9<<endl;
    }
}
