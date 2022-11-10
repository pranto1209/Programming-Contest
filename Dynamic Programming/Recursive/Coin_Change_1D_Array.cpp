#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
#define inf 1000000000
int n, w, coin[maxn], dp[maxn];

int coin_change(int w)
{
    if(w==0) return 0;
    if(dp[w]!=-1) return dp[w];

    int ans = inf;
    for(int i=1; i<=n; i++){
        if(w - coin[i] >= 0) ans = min(ans, 1 + coin_change(w - coin[i]));
    }
    return dp[w] = ans;
}

int main()
{
    cin>>n>>w;
    for(int i=0; i<=w; i++) dp[i] = -1;
    for(int i=1; i<=n; i++) cin>>coin[i];
	int ans = coin_change(w);
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
