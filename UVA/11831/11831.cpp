#include <bits/stdc++.h>

using namespace std;

char graf[105][105];
bool vis[105][105];
int m,n,ss;
string s;
int dire;
int x,y;
int cont;

void tra(char a){
	if(a=='N') dire=0;
	else if(a=='L') dire=1;
	else if(a=='S') dire=2;
	else dire=3;
}

//e= esquerda
//d= direita
//f= frent
//0= norte
//1= leste
//2= sul
//3= oeste

bool isValid(int i, int j){
	if(i>=0 && j>=0  && i<m && j<n && graf[i][j]!='#'){
		return true;
	}
	return false;
}

void ponto(int i,int j){
	vis[i][j]=true;
	if(dire==0){
		if(isValid(i-1,j)){
			x=i-1,y=j;
			if(graf[x][y]=='*' && vis[x][y]!=true){
				cont++;
			}
		}
	}
	else{
		if(dire==1){
			if(isValid(i,j+1)){
				x=i,y=j+1;
				if(graf[x][y]=='*' && vis[x][y]!=true){
					cont++;
				}
			}
		}
		else{
			if(dire==2){
				if(isValid(i+1,j)){
					x=i+1,y=j;
					if(graf[x][y]=='*' && vis[x][y]!=true){
						cont++;
					}
				}
			}
			else{
				if(isValid(i,j-1)){
					x=i,y=j-1;
					if(graf[x][y]=='*' && vis[x][y]!=true){
						cont++;
					}
				}
			}
		}
	}
}


int main(){
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>m>>n>>ss;
	while(m!=0 || n!=0|| ss!=0){
		cont=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>graf[i][j];
				if(graf[i][j]!='*' && graf[i][j]!='#'  && graf[i][j]!='.'){
					tra(graf[i][j]);
					x=i;y=j;
				}
			}
		}
		cin>>s;
		for(auto v :s){
			if(v=='D'){
				dire=(dire+1)%4;
			}
			else{
				if(v=='E'){
					dire=dire-1;
					dire = (dire<0 ? 3 : dire);
				}
				else{
					ponto(x,y);
				}
			}
		}
		cout<<cont<<endl;
		memset(vis,false,sizeof(vis));
		cin>>m>>n>>ss;
	}
}
