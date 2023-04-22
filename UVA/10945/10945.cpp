#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

string separa(string s){
	string ss="";
	for(int i=0;i<s.size();i++){
		s[i]=toupper(s[i]);
		//~ cout<<s[i]-'A'<<endl;
		if(s[i]-'A'>=0 && s[i]-'A'<=26){
			//~ cout<<"entra"<<endl;
			ss+=s[i];
		}
	}
	return ss;
}
			

bool isPalindrome(string s) {
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);

	string str,s;
	getline(cin,s);
	while(s!="DONE"){
		str=separa(s);
		//~ cout<<str<<endl;
		if(isPalindrome(str)) cout<<"You won't be eaten!"<<endl;
		else cout<<"Uh oh.."<<endl;
		getline(cin,s);
	}
}
