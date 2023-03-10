#include <bits/stdc++.h>

using  namespace std;

bool vis[30][30];
vector<string>m;
int movesx[8]={-1,-1,-1,0,0,1,1,1};
int movesy[8]={0,1,-1,-1,1,1,0,-1};
int n;
int cont;

bool isValid(int i, int j){
	if(i<0 || j<0 || i>=n || j>=m[i].size() || vis[i][j]==true || m[i][j]=='0'){
		return false;
	}
	return true;
}

void ff(int x,int y){
	vis[x][y]=true;
	cont++;	
	for(int i=0;i<8;i++){
		int nx=movesx[i]+x;
		int ny=movesy[i]+y;
		if(isValid(nx,ny)){
			ff(nx,ny);
		}
	}
}

int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int d;
	cin>>d;
	string x;
	cin.ignore();
	getline(cin,x);
	x="x";
	for(int i=0;i<d;i++){
		if(i!=0){
			cout<<endl;
		}
		int maior=0;
		vector<pair<int,int>>vi;
		n=0;
		getline(cin,x);
		while(x!="\0"){
			m.push_back(x);
			for(int j=0;j<x.size();j++){
				if(m[n][j]=='1'){
					vi.push_back({n,j});
				}
			}
			n++;
			getline(cin,x);
		}
		for(int j=0;j<vi.size();j++){
			if(vis[vi[j].first][vi[j].second]==false){
				cont=0;
				ff(vi[j].first,vi[j].second);
				if(cont>maior) maior=cont;
			}
		}
		cout<<maior<<endl;
		for(int j=0;j<vi.size();j++){
			vis[vi[j].first][vi[j].second]=false;
		}
		m.clear();
	}	
}
