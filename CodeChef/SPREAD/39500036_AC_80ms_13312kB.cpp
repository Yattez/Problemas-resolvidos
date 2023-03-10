#include <bits/stdc++.h>

using namespace std;

unsigned long long int fta[100000000];

class FenwiekTree{
private: 

	int N;
	unsigned long long int query(int id){
		unsigned long long int resp=0;
		for(;id;id=id-(id& - id)){
			resp+=fta[id];
		}
		return resp;
	}
	void upd(int id,unsigned long long int x){
		for(;id<=N;id=id+(id& - id)){
			fta[id]+=x;
		}
	}
	
public:
	FenwiekTree(){}
	FenwiekTree(int n){
		N=n+1;
	}
	unsigned long long int query(int L,int R){
		return query(R)-(L?query(L-1):0);
	}
	void up(int id,unsigned long long int x){
		upd(id,x);
	}
	void upd(int L, int R,unsigned long long int x){
		upd(L,x);
		//~ upd(R,x);
		//~ upd(R,-x);
		upd(R+1,-x);
	}
};

int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,x;
	unsigned long long int start;
	cin>>n>>x>>start;
	FenwiekTree ft(n);
	ft.upd(1,n,start);
	while(x--){
		char a;
		int l,r;
		unsigned long long int y;
		cin>>a;
		if(a=='Q'){
			cin>>l;
			cout<<ft.query(1,l)<<'\n';
		}
		else{
			cin>>l>>r>>y;
			ft.upd(l,r,y);
		}
			
	}
	
}