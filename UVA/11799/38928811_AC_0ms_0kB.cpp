#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>x;
	for(int i=0;i<n;i++){
		int h;
		cin>>h;
		for(int j=0;j<h;j++){
			int cd;
			cin>>cd;
			x.push_back(cd);
		}
		int maior=1;
		for(int j=0;j<x.size();j++){
			if(x[j]>maior){
				maior=x[j];
			}
		}
		cout<<"Case "<<i+1<<": "<<maior<<endl;
		x.clear();
	}
}
