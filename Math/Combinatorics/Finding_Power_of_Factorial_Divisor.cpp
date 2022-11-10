#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fact_pow(ll n, ll k)
{
    ll ans = 0;
    while(n) {
        n /= k;
        ans += n;
    }
    return ans;
}
int main()
{
    ll n, k;
    cin>>n>>k;
    ll ans = fact_pow(n, k);
    cout<<ans<<"\n";
}
