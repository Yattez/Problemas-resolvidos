#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int int long long
const int inf=1e12;
const int mod=1e9+7;
 
using namespace std;
 
int N=2e5;
 
class segmin{
//SegTree de minimo
public:
	
	vector<int>seg;
 
	segmin(vector<int> &a, int n){
		 seg.assign(4 * n,inf);
		for (int i = 0; i < n; i++){
			seg[n + i] = a[i];   
		}
		for (int i = n - 1; i >= 1; i--){
			seg[i] = min(seg[2 * i],seg[2 * i + 1]);
		}
	}
	 
	void update(int pos, int value,int n){
		pos += n;
		seg[pos] = value;
		while (pos > 1){
			pos >>= 1;
			seg[pos] = min(seg[2 * pos],seg[2 * pos + 1]);
		}
	}
	 
	int query(int left, int right, int n){
		left += n;
		right += n+1;
		int mi =inf;
	 
		while (left < right){
			if (left & 1) {
				mi = min(mi, seg[left]);
				left++;
			}
			if (right & 1){
				right--;
				mi = min(mi, seg[right]);
			}
			left /= 2;
			right /= 2;
		}
		return mi;
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
	int x,y;
	segmin s(v,n);
	for(int i=0;i<m;i++){
		cin>>x>>y;
		x--;
		y--;
		cout<<s.query(x,y,n)<<endl;
	}
}
