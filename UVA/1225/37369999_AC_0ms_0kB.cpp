#include <bits/stdc++.h>

using namespace std;

int vet[10];

int main(){
	int n,x;
	string str;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		for(int k=1;k<=x;k++){
			str+=to_string(k);
		}
		for(int k=0;k<str.size();k++){
			if(str[k]=='0'){
				vet[0]++;
			}
			if(str[k]=='1'){
				vet[1]++;
			}
			if(str[k]=='2'){
				vet[2]++;
			}
			if(str[k]=='3'){
				vet[3]++;
			}
			if(str[k]=='4'){
				vet[4]++;
			}
			if(str[k]=='5'){
				vet[5]++;
			}
			if(str[k]=='6'){
				vet[6]++;
			}
			if(str[k]=='7'){
				vet[7]++;
			}
			if(str[k]=='8'){
				vet[8]++;
			}
			if(str[k]=='9'){
				vet[9]++;
			}
		}
		for(int k=0;k<=9;k++){
			cout<<vet[k];
			if(k!=9){
				cout<<' ';
			}
			vet[k]=0;
		}
		cout<<endl;
		str.clear();
	}
}