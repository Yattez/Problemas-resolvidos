#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define int long long

using namespace std;
const int MAX = 3300000;


int allPalindromic(string s){
    int n = s.size();
    vector<vector<bool> > dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i < n && s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            if (s[i] == s[i + (len - 1)]
                && dp[i + 1][i + (len - 1) - 1]) {
                dp[i][i + (len - 1)] = true;
            }
        }
    }
    vector<int> kmp(n, 0);
    for (int i = 0; i < n; i++) {
        int j = 0, k = 1;
        while (k + i < n) {
            if (s[j + i] == s[k + i]) {
                dp[k + i - j][k + i] = false;
                kmp[k++] = ++j;
            }
            else if (j > 0) {
                j = kmp[j - 1];
            }
            else {
                kmp[k++] = 0;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        string str;
        for (int j = i; j < n; j++) {
            str += s[j];
            if (dp[i][j]) {
                count++;
            }
        }
    }
    return count;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    //~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	string str;
	while(cin>>str){
		int x=allPalindromic(str);
		cout<<"The string '"<<str<<"' contains "<<x<<" palindromes."<<endl;
	}
}
