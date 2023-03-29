#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
using namespace std;

int n,e;

const int inf=(int)1e9;
map<string,map<string,int>>d;
set<string>save;


void floyd(){	
	for(auto k=save.begin();k!=save.end();k++){
		for(auto i=save.begin();i!=save.end();i++){
			for(auto j=save.begin();j!=save.end();j++){
				if(( d[*i][*k]+d[*k][*j]<d[*i][*j] )&& ( d[*i][*k]!=inf && d[*k][*j]!=inf )){
					d[*i][*j] = d[*i][*k] + d[*k][*j];
				}
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>e;
	int cont=1;
	while(n || e){
		save.clear();
		d.clear();
		string x,y;
		for(int i=0;i<e;i++){
			cin>>x>>y;
			save.insert(x);
			save.insert(y);
			d[x][y]=1;
			d[y][x]=1;
		}
		int h=save.size();
		for(int i=h;i<n;i++){
			x=to_string(i*-1);
			save.insert(x);
		}
		for(auto i=save.begin();i!=save.end();i++){
			for(auto j=save.begin();j!=save.end();j++){
				if(d[*i][*j]!=1 && *i!=*j ){
					d[*i][*j]=inf;
					d[*i][*j]=inf;
				}
			}
		}
		floyd();
		int maior=-1 ;
		bool b=true;
		 for(auto i=save.begin();i!=save.end() && b;i++){
			 for(auto j=save.begin();j!=save.end() && b;j++){
				if(*i!=*j){
					if(d[*i][*j]==inf)b=false;
					else{
						if(d[*i][*j]>maior){
							maior=d[*i][*j];
						}
					}
				}
			}
		}
		cout<<"Network "<<cont++<<": ";
		if(!b)cout<<"DISCONNECTED";
		else cout<<maior;
		cout<<endl<<endl;
		cin>>n>>e;
	}
}
