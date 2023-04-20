#include <bits/stdc++.h>

using namespace std;



bool ordenas (string a,string b){
    if(a<b)return true;
    return false;
}

int main(){
    
    string str,word;
    getline(cin,str);
    vector<string>d,v;
    int n=0;
    while(str!="#"){
        stringstream ss(str);
        
        while(ss>>word){
            n++;
            d.push_back(word);
        }
        getline(cin,str);
    }
    bool b[n+1]{false};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string s1,s2;
            s1=d[i];
            s2=d[j];
            int k=0;
            while (k<=s1.size())
            {
                char c=s1[k];
                s1[k]=toupper(c);
                k++;
            }
            k=0;
            while (k<=s2.size())
            {
                char c=s2[k];
                s2[k]=toupper(c);
                k++;
            }
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1==s2){
                b[i]=true;
                b[j]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]==false){
            v.push_back(d[i]);
        }
          
    }
    sort(v.begin(),v.end(),ordenas);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
