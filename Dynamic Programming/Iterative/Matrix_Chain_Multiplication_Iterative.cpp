#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int n, a[maxn], dp[maxn][maxn];

int mcm()
{
    for(int len=2; len<=n; len++){
        for(int i=1; i<=n-len+1; i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j]);
            }
        }
    }
    return dp[1][n];
}

int main()
{
    memset(dp, 0, sizeof dp);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    n--;
    cout<<"Minimum number of multiplications is: "<<mcm()<<endl;
}

/*

4
1 2 3 4

5
1 2 3 4 3

*/
