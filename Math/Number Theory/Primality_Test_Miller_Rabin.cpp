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

ll binpow(ll a, ll b, ll mod)
{
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool check_composite(ll n, ll a, ll d, ll s)
{
    ll x = binpow(a, d, n);
    if(x==1 || x==n-1) return false;
    for(ll r=1; r<s; r++) {
        x = mulmod(x, x, n);
        if(x == n-1) return false;
    }
    return true;
}

bool miller_rabin(ll n)
{
    if(n < 2) return false;
    ll r = 0;
    ll d = n-1;
    while(d % 2 == 0) {
        d >>= 1;
        r++;
    }
    for(auto a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n == a) return true;
        if(check_composite(n, a, d, r)) return false;
    }
    return true;
}

int main()
{
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        if(miller_rabin(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
