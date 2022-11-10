#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10000];

ll fibonacci(ll n)
{
    dp[0] = 0;
    dp[1] = 1;
    for(ll i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    ll n;
    cin>>n;
    ll ans = fibonacci(n);
    cout<<ans<<"\n";
}
