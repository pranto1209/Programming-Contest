#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
int n, e, dp[1000], g[1000][1000];

int shortest_path(int u)
{
    if(u == n) return 0;
    if(dp[u]!=-1) return dp[u];
    int ret = inf;
    for(int v=0; v<=n; v++){
        if(g[u][v]!=inf){
            ret = min(ret, shortest_path(v) + g[u][v]);
        }
    }
    dp[u] = ret;
    return dp[u];
}

int main()
{
    cin>>n>>e;
    for(int i=0; i<=n; i++) dp[i]=-1;
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) g[i][j]=inf;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u][v]=w;
    }
    cout<<endl;

    shortest_path(1);

    for(int i=1; i<=n; i++){
        cout<<"Distance from Destination to "<<i<<" = "<<dp[i]<<endl;
    }
    cout<<endl;
}

/*

5 6
1 2 2
1 4 1
4 2 3
2 3 1
2 5 9
3 5 3

*/
