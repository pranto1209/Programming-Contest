#include <bits/stdc++.h>
using namespace std;
#define maxn 10000
int n, a[maxn], dp[maxn];

int lis(int i)
{
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    for(int j=i+1; j<=n; j++) {
        if(a[j] > a[i]){
            ans = max(ans, lis(j));
        }
    }
    return dp[i] = 1 + ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, lis(i));
    }
    cout<<"Lenght of LIS is: "<<ans<<endl;
}


/*

7
5 0 9 2 7 3 4

10
8 1 9 8 3 4 6 1 5 2

*/
