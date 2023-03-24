#include <bits/stdc++.h>

using namespace std;

int n,x,y;
void soma(string &s,int i,int x, int cr,int &j){
	if(i==x+1 || cr==0) return;
	
	if(s[x-i]=='1'){
		s[x-i]='0';
		j--;
	}
	else{
		s[x-i]='1';
		j++;
		cr=0;
	}
	soma(s,i+1,x,cr,j);
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	while(cin>>n){
		while(n--){
			cin>>x>>y;
			string s;
			string ss;
			for(int i=0;i<x;i++){
				s+='0';
				ss+='1';
			}
			int j=0;
			while(s!=ss){
				if(j==y)cout << s  << endl;
				soma(s,0,x-1,1,j);
			}
			if(x==y)cout <<ss << endl;
			s.clear();
			ss.clear();
			if(n)cout<<endl;
		}
	}
			
}
