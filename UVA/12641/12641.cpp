#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
bool ordenas (char a,char b){
    char a1,b1;
    a1=toupper(a);b1=toupper(b);
    if(a1==b1){
        if(a<b)return true;
        return false;
    }
    if(a1<b1)return true;
    return false;
}

string essa(string a,string b){
	char a1,b1;
	for(int i=0;i<(int)a.size();i++){
	a1=toupper(a[i]);b1=toupper(b[i]);
		if(a1==b1){
			if(a[i]<b[i])return b;
		}
		if(a1<b1)return b;
	}
	return a;
}
	


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);

    int n;
    string str1,str2,word;
    cin>>n;
   
    cin.ignore();
    while(n--){ 
		map<string,string>d;
		vector<string>p;
		getline(cin,str1);
		getline(cin,str2);
        stringstream ss(str1);
        
        while(ss>>word){
			string aux=word;
			if(aux.size()>2){
				sort(aux.begin()+1,aux.end()-1,ordenas);
			}
			if(!d.count(aux)){
				d[aux]=word;
			}
			else
				d[aux]=essa(word,d[aux]);
        }
        stringstream ss2(str2);
        while(ss2>>word){
			p.push_back(word);
        }
        for(int i=0;i<(int)p.size();i++){
			if(i!=0)cout<<" ";
			string aux=p[i];
			if(aux.size()>2){
				sort(aux.begin()+1,aux.end()-1,ordenas);
			}
			if(d.count(aux)){
				cout<<d[aux];
			}
			else cout<<p[i];
		}
		cout<<endl;
    }

}
