#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

string str1,str2;

vector<vector<int> > dp(3005, vector<int>(3005, -1));
vector<vector<int> > choice(3005, vector<int>(3005, 2));

int lcs2(int i,int j ){
	if(i==(int)str1.size()|| j==(int)str2.size())return 0;
	
	if(str1[i]==str2[j]){
		
		choice[i][j]=2;
		
		return 1+lcs2(i+1,j+1);
	}
	
	if(dp[i][j]!=-1)return dp[i][j];
	
	int x=0,y=0;
	
	x=lcs2(i+1,j);
	
	y=lcs2(i,j+1);
	if(x>y){
		
		choice[i][j]=0;
		
		return dp[i][j]=x;
	}
	choice[i][j]=1;
	
	return dp[i][j]=y;
}

string lcs(){
	int x=lcs2(0,0);
	if(x){
		int i=0, j=0;
		
		int n=str1.size(),m=str2.size();
		
		string str="";
		
		while(i<n && j<m){
			if(choice[i][j]==0){
				i++;
			}
			else{
				if(choice[i][j]==1){
					j++;
				}
				else{
					str.push_back(str1[i]);
					i++;
					j++;
				}
			}
		}
		return str;
	}
	else return "";
}

	
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	cin>>str1>>str2;
	
	cout<<lcs()<<endl;
}
	

