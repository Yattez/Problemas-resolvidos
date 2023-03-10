#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string x;

	
	while(getline(cin,x)){
		int cont=0;
		vector<string>word;
		string palavra;
		stringstream ss(x);
		bool y=false;
		for(int i=0;i<int(x.size());i++){
			if((x[i]>='A' && x[i]<='Z') ||(x[i]>='a' && x[i]<='z')){
				y=true;
			}
			else{
				if(y){
					cont++;
					y=false;
				}
			}
		}
		cout<<cont<<endl;
	}
}
