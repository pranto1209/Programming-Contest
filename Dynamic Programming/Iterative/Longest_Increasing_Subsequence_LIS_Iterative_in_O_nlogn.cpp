#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int n, a[maxn], dp[maxn];

int lis()
{
    for(int i=1; i<=n; i++) dp[i]=INT_MAX;
    dp[0]=INT_MIN;
    for(int i=1; i<=n; i++){
        int j=upper_bound(dp, dp+n, a[i])-dp;
        if(dp[j-1]<a[i] && a[i]<dp[j]) dp[j] = a[i];
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        if(dp[i]<INT_MAX) ans=i;
    }
    return ans;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<lis()<<endl;
}

/*

7
5 0 9 2 7 3 4

10
8 1 9 8 3 4 6 1 5 2

*/
