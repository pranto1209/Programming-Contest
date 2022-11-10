#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define maxn 200001
ll fact[maxn];
void findfact()
{
    fact[0] = fact[1] = 1;
    for(ll i=2; i<maxn; i++) fact[i] = fact[i-1] * i % mod;
}
ll powmod(ll a, ll b)
{
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll n)
{
    return powmod(n, mod-2);
}
ll nCr(ll n, ll r)
{
    findfact();
    return ((fact[n] * inv(fact[r])) % mod * inv(fact[n-r])) % mod;
}
int main()
{
    ll n, m;
    cin>>n>>m;
    if(n == 2) puts("0");
    else cout<<( ((n-2) * powmod(2, n-3) )%mod * nCr(m, n-1)) % mod;
}

// (n-2) * 2^(n-3) * mC(n-1)
