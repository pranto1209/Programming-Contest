#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000000
vector<ll> phi(maxn);

void sieve_phi(ll n)
{
    for(ll i=1; i<=n; i++) phi[i]=i;
    for(ll i=2; i<=n; i++) {
        if(phi[i]==i) {
            for(ll j=i; j<=n; j+=i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    sieve_phi(n);
    for(ll i=1; i<=n; i++) cout<<phi[i]<<" ";
    cout<<"\n";
}
