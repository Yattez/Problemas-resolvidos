#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int int_fast32_t
const int inf=1e12;
const int mod=1e9+7;
 
using namespace std;

struct fenwick{
    vector<int> f;
    int n;
    
    int query(int id)
	{
		int res = 0;
		for (;id;id=id-(id& -id)) // compara em bytes e acha o primeiro numero da direita para a esquerda
		{
			res+=f[id];
		} 
		return res;
		
	}
	
	void upd(int id, int x)
	{
		for (; id<=n; id=id+(id&-id))
		{
			f[id]+=x;
		}
	}
	
public:
	 fenwick(vector<int>const&v){
        n = (int)v.size();
        f.assign(n+1,0);
        for (int i=0; i<n;++i)
            upd(i+1, v[i]);
    }
	int query(int l , int r)
	{
		return query(r) - (l?query(l-1):0);
	}
	
	void up(int id, int x)
	{
		upd(id, x);//precisa comecar com id = 1
	}
	
	void upd(int l, int r, int x)
	{
		upd(l,x);
		up(r+1, -x);
	}
};

int n,m;
	 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	fenwick f(v);
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		cout<<f.query(x,y)<<endl;
	}
}
