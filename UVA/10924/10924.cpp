#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

const int MAX = 3300000;
vector <int> primes;

map<char,int>traducao;

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

void gerarTraducao(){
	int i=0;
	char l='a';
	char ll='A';
	for(i=0;i<26;i++){
		char aux=l+i;
		traducao[aux]=i+1;
	}
	for(;i<52;i++){
		char aux=ll+i-26;
		traducao[aux]=i+1;
	}
}

int traduzir(string str){
	int x=0;
	for(int i=0;i<str.size();i++){
		x+=traducao[str[i]];
	}
	return x;
}
	
	
	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);   
	gerarPrime();
	gerarTraducao();
	string str;
	while(cin>>str){
		int n=traduzir(str);
		if(binary_search(primes.begin(),primes.end(),n)){
			cout<<"It is a prime word."<<endl;
		}
		else cout<<"It is not a prime word."<<endl;
		
	}
			
}

