#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b,r = "";
	int f,t,cont=0;
	vector<int>dif;
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			dif.push_back(i);
		}
	}
	if(!dif.empty()){
		f=dif.front();
		t=dif.back();
		for(int i=f;i<=t;i++){
		r+=b[i];
			cont++;
		}
		for(int i=0;i<cont;i++){
			b[t-i]=r[i];
		}
	}	
	if(a==b){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
