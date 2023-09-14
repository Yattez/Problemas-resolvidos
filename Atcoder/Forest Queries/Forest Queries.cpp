#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long
const int inf=1e12;
const int mod=1e9+7;
 
using namespace std;

const int maxn = (int)1e4+5;

int f[maxn][maxn];
int n;

void upd(int x, int y,int val){
	while(x <= n){
		int y1 = y;
		while(y1 <= n){
			f[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int query(int x, int y){
	int soma = 0;
	while(x){
		int y1 = y;
		while(y1){
			soma += f[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return soma;
}

int query(int x1, int y1, int x2, int y2){
	return (query(x2, y2) - query(x1 - 1, y2)- query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int m;
	cin>>n>>m;
	char x;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>x;
			if(x=='*')upd(i+1,j+1,1);
			else upd(i+1,j+1,0);
		}
	}
	int a,b,c,d;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		cout<<query(a,b,c,d)<<endl;
	}
}
