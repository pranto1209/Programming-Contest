#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000
ll dp[maxn][maxn];

ll nCr(int n, int r)
{
    cout<<n<<" "<<r<<endl;
    if(r == 1) return n;
    if(r == n or r == 0) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
    return dp[n][r];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, r;
    cin>>n>>r;
    int ans = nCr(n, r);
    cout<<ans<<"\n";
}
