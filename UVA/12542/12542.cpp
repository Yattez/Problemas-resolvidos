#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
vector<int> primes;
const int MAX = 1300000;
int dp[200][20][1130];

void gerarPrime(){
    bool marked[MAX/2 + 100] = {0};
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
    primes.push_back(2);
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}


int find(int i,int j,int s,int n,int m){
	if(s==n && j==m){
		return 1;
	}
	if(j>m || s>n || primes[i]>n || i>(int)primes.size())
		return 0;
	if(dp[i][j][s]!=-1){
		return dp[i][j][s];
	}
	int x=0,y=0;
	x=find(i+1,j+1,s+primes[i],n,m);
	y=find(i+1,j,s,n,m);
	
	return dp[i][j][s]=x+y;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	gerarPrime();
	int n,m;
	cin>>n>>m;
	while(n!=0 || m!=0){
		memset(dp,-1,sizeof(dp));
		cout<<find(0,0,0,n,m)<<endl;
		cin>>n>>m;
	}
}
