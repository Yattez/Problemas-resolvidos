#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
const int MAX = 1300000;
vector <int> primes;
 
void sieveSundaram(){
    bool marked[MAX/2 + 100] = {0};
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
    primes.push_back(2);
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}
 
void findPrimes(int n){
	if (binary_search (primes.begin(), primes.end(), n) || n==1){
		cout<<0<<endl;
	}
	else{
		int x,y;
		x=y=upper_bound(primes.begin(), primes.end(),n)-primes.begin();
		x--;
		cout<<primes[y]-primes[x]<<endl;
	}
    
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	sieveSundaram();
	int n;
	cin>>n;
	while(n!=0){
		findPrimes(n);
		cin>>n;
	}
}
