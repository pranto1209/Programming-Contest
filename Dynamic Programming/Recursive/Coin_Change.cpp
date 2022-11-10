#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
#define inf 1000000
int n, w, coin[maxn], dp[maxn][maxn];

int coin_change(int i, int w)
{
    if(w<0) return inf;
    if(i>n) {
        if(w == 0) return 0;
        else return inf;
    }
    if(dp[i][w] != -1) return dp[i][w];
    int ret1 = 1 + coin_change(i, w-coin[i]);
    int ret2 = coin_change(i+1, w);
    return dp[i][w] = min(ret1, ret2);
}

int main()
{
    cin>>n>>w;
    for(int i=0; i<=n; i++) for(int j=0; j<=w; j++) dp[i][j] = -1;
    for(int i=1; i<=n; i++) cin>>coin[i];
	int ans = coin_change(1, w);
	cout<<ans<<"\n";
}

/*

5 150
5 8 11 15 18

4 13
7 2 3 6

3 5
1 2 3

*/
