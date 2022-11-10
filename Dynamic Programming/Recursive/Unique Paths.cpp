#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int n, m, a[maxn][maxn], dp[maxn][maxn];

bool valid(int x, int y)
{
    if(x < n and y < m and a[x][y]) return true;
    else return false;
}

int solve(int i, int j)
{
    if(!valid(i, j)) return 0;
    if(i >= n-1 and j >= m-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = solve(i+1, j) + solve(i, j+1) + solve(i+1, j+1);
    return dp[i][j] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];
    int ans = solve(0, 0);
    cout<<ans<<"\n";
}

/*

4 4
1 1 0 1
1 1 1 1
1 1 0 1
0 1 1 1

*/
