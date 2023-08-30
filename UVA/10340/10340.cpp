
#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

string str1,str2;

bool check(int i,int j ){
	if(i==(int)str1.size())return true;
	if(j==(int)str2.size())return false;
	
	bool b;
	if(str1[i]==str2[j]) b=check(i+1,j+1);
	else b=check(i,j+1);
	
	return b;
	
}
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);]
	
	while(cin>>str1>>str2){
		if(check(0,0)){
			cout<<"Yes"<<endl;
		}
		else  cout<<"No"<<endl;
		
	}
}
	
