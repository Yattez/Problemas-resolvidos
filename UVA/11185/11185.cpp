#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
void convertToTernary(int N){
    if (N == 0)
        return;
    int x = N % 3;
    N /= 3;
    if (x < 0)
        N += 1;
    convertToTernary(N);
    if (x < 0)
        cout << x + (3 * -1);
    else
        cout << x;
}
 
void convert(int Decimal)
{
    if (Decimal != 0) {
        convertToTernary(Decimal);
        cout<<endl;
    }
    else
        cout << "0"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);   
	int n;
	cin>>n;
    while(n>=0){
		convert(n);
		cin>>n;
	}
}

