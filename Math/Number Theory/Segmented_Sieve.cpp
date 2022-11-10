#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
vector<ll> primes, segprimes, pr(maxn, 1);

void sieve()
{
    for(ll i=3; i*i<=maxn; i+=2) {
        if(pr[i]) {
            for(ll j=i*i; j<=maxn; j+=i) {
                pr[j] = 0;
            }
        }
    }
    primes.push_back(2);
    for(ll i=3; i<maxn; i+=2) if(pr[i]) primes.push_back(i);
}

void segSieve(ll l, ll r)
{
    vector<ll> isPrime(r-l+1, 1);
    if(l == 1) isPrime[0] = 0;
    for(ll i=0; primes[i]*primes[i]<=r; i++) {
        ll cp = primes[i];
        ll base = (l / cp) * cp;
        if(base < l) base += cp;
        for(ll j=base; j<=r; j+=cp) {
            isPrime[j-l] = 0;
        }
        if(base == cp) isPrime[base-l] = 1;
    }
    segprimes.clear();
    for(ll i=0; i<r-l+1; i++) if(isPrime[i]) segprimes.push_back(i+l);
}

int main()
{
    sieve();
    ll t;
    cin>>t;
    while(t--) {
        ll l, r;
        cin >> l >> r;
        segSieve(l, r);
        for(auto i: segprimes) cout<<i<<" ";
        cout<<"\n";
    }
}
