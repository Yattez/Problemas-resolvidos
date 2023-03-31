#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
vector<int> tiro;
int n,meta;
bool ok=false;
vector<int>save;
void back(int m,vector<int>r){
	if(m<=0){
		
		if(m==0){
			ok=true;
			if(r.size()<save.size())save=r;
			else{
				bool b=true;
				for(int i=0;i<(int)save.size() && b;i++){
					//~ cout<<save[i]<<" "<<r[i]<<endl;
					if(save[i]>r[i])b=false;
				}
				if(b)save=r;
			}
		}
		return;
	}

	for(int i=0;i<n;i++){
		
		if(m-tiro[i]>=0 &&  r.size()<=save.size())
		{
			r.push_back(tiro[i]);
			back(m-tiro[i],r);
			r.pop_back();
		}
	}
	return;
}



signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	int t,cont=0;
	cin>>t;
	for(int i=0;i<t;i++){
		ok=false;
		cin>>n>>meta;
		int x;
		tiro.clear();
		for(int j=0;j<n;j++){
			cin>>x;
			tiro.push_back(x);
		}
		reverse(tiro.begin(),tiro.end());
		vector<int>r;
		save=tiro;
		while((int)save.size()<=meta+2){
			save.push_back(-1);
		}
		back(meta,r);
		cout<<"Case "<<++cont<<": ";
		if(ok){
			
			//~ reverse(save.begin(),save.end());
			 cout<<"["<<(int)save.size()<<"]";
			for(int k=0;k<(int)save.size();k++){
				cout<<" "<<save[k];
				
			}
		}
		else{
			cout<<"impossible";
		}
		cout<<endl;
	}
}
