#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
int skew(string str){
	int sum=0;
	for(int i=0;i<str.size();i++){
		int x=(str[i]-'0')*(pow(2,str.size()-i)-1);
		sum+=x;
	}
	return sum;	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);   
	string str;
	cin>>str;
	while(str!="0"){
		cout<<skew(str)<<endl;
		//~ cout<<str<<endl;
		cin>>str;
	}
	
}
