#include <bits/stdc++.h>

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

int main(){
    int n;
    string str;
    cin>>n;
    while(n--){
        cin>>str;
        sort(str.begin(),str.end(),ordenas);
        cout<<str<<endl;
        while (next_permutation(str.begin(),str.end(),ordenas))cout<<str<<endl;
    }
}
