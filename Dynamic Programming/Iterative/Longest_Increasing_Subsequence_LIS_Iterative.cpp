#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int n, a[maxn], dp[maxn];

void lis()
{
    for(int i=0; i<=n; i++) dp[i]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[i]>a[j]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    lis();

    int ans=0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<"Lenght of LIS is: "<<ans<<endl;
}

/*

7
5 0 9 2 7 3 4

10
8 1 9 8 3 4 6 1 5 2

*/
