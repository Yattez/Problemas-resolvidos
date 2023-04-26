#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

vector<int> primes;
vector<int>par;
const int MAX = 18409501;

void gerarPrime(){
    bool marked[MAX/2 + 100] = {0};
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
            
    primes.push_back(2);
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
            
    for(int i=0;i<primes.size()-1;i++){
		if(primes[i]==primes[i+1]-2){
			par.push_back(primes[i]);
			par.push_back(primes[i+1]);
		}
	}
}

	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	gerarPrime();
	int n;
	while(cin>>n){
		cout<<"("<<par[(2*n-2)]<< ", "<<par[(2*n-1)]<<")"<<endl;
	}	
}
