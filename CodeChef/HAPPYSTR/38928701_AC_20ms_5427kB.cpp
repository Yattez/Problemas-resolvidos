#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	for(int i=0;i<n;i++){
		cin>>str;
		bool b=false;
		for(int j=0;j<str.size() && b==false;j++){
			int cont=0;
			
			for(int k=j;k<j+3 && k<str.size() ;k++){
				if(str[k]=='a' ||str[k]=='e' ||str[k]=='i' ||str[k]=='o' ||str[k]=='u'){
					cont++;
				}
				
			}
			if(cont>=3){
				b=true;
			}
		}
		if(b){
			cout<<"Happy"<<endl;
		}
		else{
			cout<<"Sad"<<endl;
		}
	}
}
