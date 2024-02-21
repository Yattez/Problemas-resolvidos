#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int int_fast32_t
const int inf=1e12;
const int mod=1e9+7;
 
using namespace std;
 
int n,m;
 
const int MAXN = 4*1e5+1;
vector<int> segtree(MAXN);
 
void build(vector<int>&v){
	for(int i=0;i<n;i++) segtree[n+i]=v[i];  
	
	for(int i=n-1;i>=1;i--)segtree[i]=max(segtree[2*i],segtree[2*i+1]);  
}
 
void update(int p,int v){
 
	p+=n;
	segtree[p]-=v;
 
	while (p > 1) {
		p >>= 1;
		segtree[p] = max(segtree[2*p],segtree[2*p+1]);
	}
}
 
 
int query(int l, int r){
	l+=n;
	r+=n;
	int m =-1;
	while(l<r){
		if(l & 1){
			m=max(m,segtree[l]);
			l++;
		}
		if (r & 1) {
			r--;
			m = max(m, segtree[r]);
		}
		l/= 2;
		r/= 2;
	}
	return m;
}
 
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v[i]=x;
	}
	build(v);
	
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		int l=0,r=n+1;
		while(l<r){
			int m=(l+r)/2;
			if(query(0,m)<x){
				 l=m+1;
			}
			else r=m;
		}
		if(l>n)cout<<0<<' ';
		else {
			cout<<l<<' ';
			
			update(l-1,x);
		}
	}
}
