#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int n, a[maxn][maxn], dp[maxn][maxn];

int maze(int i, int j)
{
    if(i==n-1 && j==n-1) return 1;
    if(i>=0 && i<n && j>=0 && j<n && a[i][j]!=-1){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = maze(i+1, j) || maze(i+1, j+1) || maze(i, j+1);
        return dp[i][j];
    }
    else return 0;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j]=-1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];
    cout<<maze(0, 0)<<endl;
}

/*

4
1 1 -1 -1
1 1 -1 1
1 -1 -1 -1
1 1 1 1

*/

