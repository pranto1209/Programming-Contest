#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll factmod(ll n, ll p)
{
    ll res = 1;
    while(n > 1) {
        res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
        for(ll i=2; i<=n%p; i++) res = res * i % p;
        n /= p;
    }
    return res % p;
}

int main()
{
    ll n, p;
    cin>>n>>p;
    ll ans = factmod(n, p);
    cout<<ans<<"\n";
}
