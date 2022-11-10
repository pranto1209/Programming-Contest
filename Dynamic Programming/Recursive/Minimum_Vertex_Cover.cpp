#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int dp[maxn][2], par[maxn];
vector<int>g[maxn];

int mvc(int u, bool isGuard)
{
    if(dp[u][isGuard]!=-1) return dp[u][isGuard];
    int sum = isGuard;
    for(int v: g[u]){
        if(v!=par[u]){
            par[v]=u;
            if(isGuard==0) sum += mvc(v, true);
            else sum += min(mvc(v, true), mvc(v, false));
        }
    }
    return dp[u][isGuard] = sum;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = min(mvc(1, true), mvc(1, false));
    cout<<ans<<endl;
}


/*

8
1 2
1 3
2 4
2 5
3 6
5 7
5 8

*/
