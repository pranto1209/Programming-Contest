#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
int dp[maxn][maxn];
string s, t;

int lcs(int i, int j)
{
    if(i == s.size() or j == t.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(s[i] == t[j]) ans = 1 + lcs(i+1, j+1);
    else ans = max(lcs(i+1, j), lcs(i, j+1));
    return dp[i][j] = ans;
}

int main()
{
    for(int i=0; i<maxn; i++) for(int j=0; j<maxn; j++) dp[i][j] = -1;
    cin>>s>>t;
    int ans = lcs(0, 0);
    cout<<ans<<"\n";
}


/*

HELLOM
HMRLL

*/
