#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int n, a[maxn], dp[maxn], dir[maxn];

void path(int v)
{
    cout<<a[v]<<" ";
    if(dir[v] != -1) path(dir[v]);
}

int lis(int i)
{
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    for(int j=i+1; j<=n; j++) {
        if(a[j] > a[i]) {
            int ls = lis(j);
            if(ls > ans) {
                ans = ls;
                dir[i] = j;
            }
        }
    }
    return dp[i] = 1 + ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    memset(dir, -1, sizeof(dir));
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    int ans=0, pos;
    for(int i=1; i<=n; i++){
        int ls=lis(i);
        if(ls>ans){
            ans=ls;
            pos=i;
        }
    }
    cout<<"Lenght of LIS is: "<<ans<<endl;
    path(pos);
}


/*

7
5 0 9 2 7 3 4

10
8 1 9 8 3 4 6 1 5 2

*/
