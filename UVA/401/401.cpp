#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

map<char,char>r;

// % PRA NÃO TEM 
void rev(){
	r['A']='A';
	r['B']='%';
	r['C']='%';
	r['D']='%';
	r['E']='3';
	r['F']='%';
	r['G']='%';
	r['H']='H';
	r['I']='I';
	r['J']='L';
	r['K']='%';
	r['L']='J';
	r['M']='M';
	r['N']='%';
	r['O']='O';
	r['P']='%';
	r['Q']='%';
	r['R']='%';
	r['S']='2';
	r['T']='T';
	r['U']='U';
	r['V']='V';
	r['W']='W';
	r['X']='X';
	r['Y']='Y';
	r['Z']='5';
	r['1']='1';
	r['2']='S';
	r['3']='E';
	r['4']='%';
	r['5']='Z';
	r['6']='%';
	r['7']='%';
	r['8']='8';
	r['9']='%';
}
	
	
bool mirror(string s){
	int t=s.size();
	bool b=true;
	for(int i=0,j=t-1;i<t/2 && j>t/2-1 && b;i++,j--){
		if(s[i]==0)s[i]='O';
		if(s[j]==0)s[j]='O';
		char c=s[i];
		char cc=s[j];
		if(r[c]=='%' || r[cc]=='%'){
			b=false;
		}
		if(r[c]!=cc){
			b=false;
		}
	}
	if(t%2==1){
		if(r[s[t/2]]!=s[t/2])b=false;
	}
	return b;
}

bool isPalindrome(string s) 
{
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < j) 
    {
        if (s[i] != s[j]) 
        {
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
	string str;
	
	rev();
	
    while(cin>>str){
		bool mir=false,pa=false;
		if(str.size()==1){
			pa=true;
			if(r[str[0]]==str[0])mir=true;
			else mir=false;
		}
		else{
			mir=mirror(str);
			pa=isPalindrome(str);
		}
		cout<<str;
		if(mir && pa)cout<<" -- is a mirrored palindrome."<<endl;
		else if(mir && !pa)cout<<" -- is a mirrored string."<<endl;
		else if(!mir && pa)cout<<" -- is a regular palindrome."<<endl;
		else cout<<" -- is not a palindrome."<<endl;
		cout<<endl;
	}

}
