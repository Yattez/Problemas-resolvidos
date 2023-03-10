#include <bits/stdc++.h>


using namespace std;

const int K = 27;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
	int quant=0;
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1); 
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
      
		v = t[v].next[c]; 
        t[v].quant++;
         
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int main(){
	int n,m;
	string s,x;
	cin>>n>>m;
	while (n--){
		cin>>s;
		add_string(s);
	}
	while(m--){
		cin>>x;
		int v=0;
		bool y=true;
		for(int i=0;i<int(x.size()) && y;i++){
			int c =x[i]-'a';
			if(t[v].next[c]!=-1){
				v=t[v].next[c];
			}
			else{
				y=false;
			}
		}
		int tem=0;
		if(y==true){
			tem=t[v].quant;
		}
		cout<<tem<<endl;
	}
}
