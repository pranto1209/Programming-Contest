#include<bits/stdc++.h>
using namespace std;
int dp[5001][1001];
void fib()
{
    int i,j;
    dp[0][0]=0;
    dp[1][0]=dp[2][0]=1;
    for(int i=3; i<5001; i++){
        for(int j=0; j<1001; j++){
            dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i-2][j];
            if(dp[i][j]>=10){
                dp[i][j+1]=dp[i][j]/10;
                dp[i][j]=dp[i][j]%10;
            }
        }
    }
}
int main()
{
    fib();
    int n, i, j;
    while(cin>>n){
        for(i=1001-1; i>=0; i--) if(dp[n][i]!=0) break;
        for(j=i; j>=0; j--) printf("%d", dp[n][j]);
        printf("\n");
    }
}
