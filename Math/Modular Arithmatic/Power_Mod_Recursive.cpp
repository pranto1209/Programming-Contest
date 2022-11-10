#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll powmod(ll a, ll b)
{
    if(b == 0) return 1;
    ll res = powmod(a, b/2);
    if(b & 1) return res * res * a % mod;
    else return res * res % mod;
}

int main()
{
    ll a, b;
    cin>>a>>b;
    ll ans = powmod(a, b);
    cout<<ans<<"\n";
}
