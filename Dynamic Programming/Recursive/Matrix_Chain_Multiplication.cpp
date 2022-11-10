#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int n, a[maxn], dp[maxn][maxn];

int mcm(int i, int j)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ret=INT_MAX;
    for(int k=i; k<j; k++){
        ret = min(ret, mcm(i, k) + mcm(k+1, j) + a[i-1]*a[k]*a[j]);
    }
    dp[i][j]=ret;
    return dp[i][j];
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    n--;
    cout<<"Minimum number of multiplications is: "<<mcm(1, n)<<endl;
}

/*

4
1 2 3 4

5
1 2 3 4 3

*/
