#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;



bool ordenas1 (char a,char b){
    char a1,b1;
    a1=toupper(a);b1=toupper(b);
    if(a1==b1){
        if(a<b)return true;
        return false;
    }
    if(a1<b1)return true;
    return false;
}

bool ordenas2 (string a,string b){
    if(a<b)return true;
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
    string str;
	map<string,vector<string>>m;
    cin>>str;
    while(str!="XXXXXX"){
		string aux=str;
		sort(aux.begin(),aux.end(),ordenas1);
		m[aux].push_back(str);
		
		cin>>str;
    }
    cin>>str;
     while(str!="XXXXXX"){
		sort(str.begin(),str.end(),ordenas1);
		if(m.count(str)){
			sort(m[str].begin(),m[str].end(),ordenas2);
			for(int i=0;i<(int)m[str].size();i++){
				cout<<m[str][i]<<endl;
			}
		}
		else cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
		cin>>str;
    }
}
