#include<bits/stdc++.h>
using namespace std;
#define maxn 10
#define inf 1061109567
int n, e, g[maxn][maxn], dp[maxn][1<<maxn];

int turnOn(int x, int pos){
    return x | (1<<pos);
}
int turnOff(int x, int pos){
    return x & ~(1<<pos);
}
bool isOn(int x, int pos){
    return x & (1<<pos);
}

int tsp(int i, int mask)
{
    if(mask==(1<<n)-1) return g[i][0];
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ret=inf;
    for(int j=0; j<n; j++){
        if(g[i][j]==-1) continue;
        if(isOn(mask, j)==0){
            ret = min(ret, g[i][j] + tsp(j, turnOn(mask, j)));
        }
    }
    return dp[i][mask] = ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    memset(g, -1, sizeof g);
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u][v]=w;
    }
    cout<<tsp(0, 1)<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<32; j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}

/*

5 8
0 1 1
0 3 9
1 2 3
2 3 4
2 4 2
3 1 2
3 4 3
4 0 4

*/
