#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;


bool ordenas (char a,char b){
    char a1,b1;
    a1=toupper(a);b1=toupper(b);
    if(a1==b1){
        if(a<b)return true;
        return false;
    }
    if(a1<b1)return true;
    return false;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
    int n;
    string str;
    cin>>n;
    while(n--){
        cin>>str;
        sort(str.begin(),str.end(),ordenas);
        cout<<str<<endl;
        while (next_permutation(str.begin(),str.end(),ordenas))cout<<str<<endl;
        cout<<endl;
    }
}
