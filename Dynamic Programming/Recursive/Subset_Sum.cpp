#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
int n, w, coin[maxn], dp[maxn][maxn];

int subset_sum(int i, int w)
{
    if(w < 0) return 0;
    if(i > n) {
        if(w == 0) return 1;
        else return 0;
    }
    if(dp[i][w] != -1) return dp[i][w];
    int ret1 = subset_sum(i+1, w-coin[i]);
    int ret2 = subset_sum(i+1, w);
    return dp[i][w] = ret1 + ret2;
}

int main()
{
    cin>>n>>w;
    for(int i=0; i<maxn; i++) for(int j=0; j<maxn; j++) dp[i][j] = -1;
    for(int i=1; i<=n; i++) cin>>coin[i];
	int ans = subset_sum(1, w);
	cout<<ans<<"\n";
}

/*

5 150
5 8 11 15 18

3 5
1 2 3

*/
