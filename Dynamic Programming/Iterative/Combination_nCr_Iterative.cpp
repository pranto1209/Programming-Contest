#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000
ll dp[maxn][maxn];

ll nCr(int n, int r)
{
    for(int i=0; i<=n; i++){
        for(int j=0; j<=r; j++){
            if(j==1) dp[i][j] = i;
            else if(j==i || j==0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    return dp[n][r];
}
int main()
{
    int n, r;
    cin>>n>>r;
    cout<<nCr(n, r)<<endl;
}
