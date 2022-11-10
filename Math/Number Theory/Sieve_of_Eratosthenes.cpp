#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
vector<ll> primes, pr(maxn, 1);

void sieve(ll n)
{
    pr[1] = 0;
    for(ll i=4; i<=n; i+=2) pr[i] = 0;
    for(ll i=3; i*i<=n; i+=2) {
        if(pr[i]) {
            for(ll j=i*i; j<=n; j+=i) pr[j]=0;
        }
    }
    for(ll i=1; i<=n; i++) if(pr[i]) primes.push_back(i);
}

int main()
{
    ll n;
    cin>>n;
    sieve(n);
    cout<<primes.size()<<"\n";
    for(auto i: primes) cout<<i<<" ";
    cout<<"\n";
}
