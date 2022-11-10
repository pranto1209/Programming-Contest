#include <bits/stdc++.h>
using namespace std;
#define maxn 2005
#define inf 1000000000
int n, w, weight[maxn], cost[maxn], dp[maxn][maxn];

int knapsack(int i, int w)
{
    if(w<0) return -inf;
    if(i>n or w==0) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int ret1 = cost[i] + knapsack(i+1, w-weight[i]);
    int ret2 = knapsack(i+1, w);
    return dp[i][w] = max(ret1, ret2);
}

int main()
{
    cin>>n>>w;
    for(int i=0; i<=n; i++) for(int j=0; j<=w; j++) dp[i][j] = -1;
    for(int i=1; i<=n; i++) cin>>weight[i]>>cost[i];
    int ans = knapsack(1, w);
    cout<<ans<<"\n";
}

/*

5 4
1 8
2 4
3 0
2 5
2 3

*/
