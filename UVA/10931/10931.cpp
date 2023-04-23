#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;

int findSum(string str){
    int sum = 0;
    for (auto ch : str) {
        if (isdigit(ch)){
            sum += ch-'0';
        }
	}
    return sum;
}
string decimalToBinary(int n){
	int arr[1000], i = 0;
    string str="";
	while(n != 0){
		arr[i] = n % 2;
		i++;
		n = n / 2;
	}
	for(i = i - 1; i >= 0;i--){
		str+=to_string(arr[i]);
	}
	return str;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);   
	int n;
	cin>>n;
	while(n!=0){
		string str=decimalToBinary(n);
		cout<<"The parity of "<<str<<" is "<<findSum(str)<<" (mod 2)."<<endl;
		cin>>n;
	}
	
}
