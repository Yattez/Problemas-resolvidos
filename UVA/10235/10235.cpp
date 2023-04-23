#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

const int MAX = 3300000;
vector <int> primes;

void gerarPrime(){
	primes.push_back(1);
    bool marked[MAX/2 + 100] = {0};
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
    primes.push_back(2);
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
  //~ freopen("input.txt","r",stdin);
  //~ freopen("output.txt","w",stdout);   
	gerarPrime();
	int n;
	while(cin>>n){
		int x=n;
		if(binary_search(primes.begin(),primes.end(),n)){
			string str;
			str=to_string(n);
			reverse(str.begin(), str.end());
			n=stoll(str,nullptr,10);
			if( n!=x && binary_search(primes.begin(),primes.end(),n)){
				
				cout<<x<<" is emirp."<<endl;
			}
			else cout<<x<<" is prime."<<endl;
		}
		else cout<<x<<" is not prime."<<endl;
	}
			
}

