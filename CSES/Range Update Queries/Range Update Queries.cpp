#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf=1e12;
const int mod=1e9+7;
 
using namespace std;
 
const int MAXN = 2*1e5+1;
vector<int> b1(MAXN,0),b2(MAXN,0);
 
void update(vector<int>& ft,int  p, int v)
{
  for (; p <= MAXN; p += p&(-p))
    ft[p] += v;
} 	 
 
void update(int l, int r, int v)
{ 	
  update(b1, l, v); 	
  update(b1, r + 1, -v); 	
  update(b2, l, v * (l-1)); 	
  update(b2, r + 1, -v * r); 	 
}
 
int query(vector<int>& ft, int b)
{ 	
  int sum = 0; 	
  for(; b > 0; b -= b&(-b))
    sum += ft[b];
  return sum;
}
int query(int idx)
{
  return query(b1, idx) * idx - query(b2, idx);
}
 
int query(int a, int b)
{
  return query(b) - query(a-1);
} 
int n,m;
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>m;
	vector<int>v(n);
	for(int i=1;i<=n;i++)
	{int x;
		
		cin>>x;
		update(i,i,x);
		
	}
	int x,y,z,w;
	for(int i=0;i<m;i++){
		cin>>w>>x;
		if(w==1){
			cin>>y>>z;
			update(x, y,z);
			//f.upd(x,y,z);
			//f.a();
		}
		else cout<<query(x,x)<<endl;
	}
}
