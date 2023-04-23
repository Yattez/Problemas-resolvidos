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
	int n,c;
	gerarPrime();
	while(cin>>n>>c){
		int h=c;
		int x;
		x=upper_bound(primes.begin(), primes.end(),n)-primes.begin();
		if(x%2==0)c=c*2;
		else c=c*2-1;
		priority_queue<int,vector<int>,greater<int>>pq;
		if(c<n){
			int aux1,aux2;
			aux1=x/2;
			aux2=x/2-1;
			while(c){
				if(c){
					if(primes[aux1]<=n)pq.push(primes[aux1]);
					aux1++;
					c--;
				}
				if(c){
					if(aux2>=0)pq.push(primes[aux2]);
					aux2--;
					c--;
				}
			}
		}
		else{
			int x=primes[0];
			int k=1;
			pq.push(x);
			while(x<n){
				x=primes[k];
				if(x<=n){
					pq.push(x);
				}
				k++;
			}
		}
		cout<<n<<" "<<h<<":";
		while(!pq.empty()){
			cout<<" "<<pq.top();
			pq.pop();
		}
		cout<<endl<<endl;
	}
}

