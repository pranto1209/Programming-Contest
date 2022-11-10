#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int r, c, a[maxn][maxn], dp[maxn][maxn];

int call(int i, int j)
{
    if(i>=0 && i<r && j>=0 && j<c){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = max({call(i+1, j) + a[i][j], call(i+1, j+1) + a[i][j], call(i+1, j-1) + a[i][j]});
        return dp[i][j];
    }
    else return 0;
}

int main()
{
    cin>>r>>c;
    for(int i=0; i<=r; i++) for(int j=0; j<=c; j++) dp[i][j]=-1;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin>>a[i][j];
    cout<<call(0, 0)<<endl;
}

/*

3 3
-1 2 5
4 -2 3
11 12 10

*/
