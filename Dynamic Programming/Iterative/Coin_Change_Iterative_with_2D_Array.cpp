#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
#define inf 1000000
int n, w, coin[maxn], dp[maxn][maxn], dir[maxn];

int coin_change()
{
    for(int i=1; i<=w; i++) dp[0][i]=i;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(j-coin[i]>=0) dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coin[i]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int main()
{
    cin>>n>>w;
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=1; i<=n; i++) cin>>coin[i];
	cout<<coin_change()<<endl;
}

/*

5 150
5 8 11 15 18

4 18
2 3 6 7

3 5
1 2 3

*/
