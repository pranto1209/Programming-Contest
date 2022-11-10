#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
ll inv[mod];

int main()
{
    ll n;
    cin>>n;
    inv[1]=1;
    for(ll i=2; i<=n; i++) inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
    for(ll i=1; i<=n; i++) cout<<inv[i]<<"\n";
}
