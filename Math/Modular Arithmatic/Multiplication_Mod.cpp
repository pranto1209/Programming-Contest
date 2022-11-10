#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0, y = a % mod;
    while(b > 0) {
        if(b & 1) x = (x + y) % mod;
        y = 2 * y % mod;
        b >>= 1;
    }
    return x % mod;
}

int main()
{
    ll a, b, mod;
    cin>>a>>b>>mod;
    ll ans = mulmod(a, b, mod);
    cout<<ans<<"\n";
}
