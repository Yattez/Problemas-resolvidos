#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;


int freq[58];

int formpalindrome(string s) {
    memset(freq, 0, sizeof(freq));

    for (char c : s){
		if(c==' ')c='_';
        freq[c-'A']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 58; i++){
        if (freq[i] % 2 == 1){
            oddCount++;
        }
    }
    return oddCount;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	string str;
	getline(cin,str);
	while(str!="#"){
		int n=formpalindrome(str);
		if(n==0 ||n==1 || str=="/0"){
			cout<<endl;
		}
		else {
			while(n>1){
				for (int i = 0; i < 58 && n!=1; i++){
					if (freq[i] % 2 == 1){
						char c='A'+i;
						cout<<c;
						n--;
					}
				}
			}
			cout<<endl;
		}
			
		getline(cin,str);
	}
}
