#include <bits/stdc++.h>

using namespace std;

vector<string> vec;
map<string,bool>vis;

int bfs(string origem,string destino){
	queue<pair<int,string>> q;
	vis[origem]=true;
	q.push({0,origem});
	while(!q.empty()){
		auto u=q.front(); 
		q.pop();
		if(u.second==destino) return u.first;
		auto x=u.second;
		for(int i=0;i<vec.size();i++){
			int cont=0;
			string y=vec[i];
			for(int j=0;j<y.size();j++){
				if(x[j]!=y[j]){
					cont++;
				}
			}
			if(cont==1 && x.size()==y.size()&& !vis[y]){
				q.push({u.first+1,y});
				vis[y]=true;
			}
		}
	}
	return -1;
}	

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n; cin>>n;
	string ex;
	getline(cin, ex);
	for(int i=0;i<n;i++){
		if(i>0){
			cout<<endl;
		}
		getline(cin, ex);
		while(ex!="*"){
			vec.push_back(ex);
			getline(cin, ex);
		}
		getline(cin, ex);
		while(ex!=""){
			vector<string>from;
			string str;
			stringstream ss(ex);
			while(ss>>str){
				from.push_back(str);
			}
            cout<<from[0]<<' '<<from[1]<<' ';
            cout<<bfs(from[0],from[1])<<endl;
            vis.clear();
            from.clear();
			getline(cin, ex);
		}
		vec.clear();
	}
}