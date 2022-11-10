#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int n, w, weight[maxn], cost[maxn], dp[maxn][maxn];

int knapsack()
{
    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(j-weight[i]>=0) dp[i][j] = max(dp[i-1][j], cost[i] + dp[i-1][j-weight[i]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int main()
{
    cin>>n>>w;
    for(int i=1; i<=n; i++) cin>>weight[i]>>cost[i];
    cout<<knapsack()<<endl;
}

/*

3 5
1 60
2 100
3 120

4 7
1 1
3 4
4 5
5 7

*/
