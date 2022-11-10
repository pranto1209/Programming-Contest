#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
vector<ll> pfact, primes, pr(maxn, 1);

void sieve(ll n)
{
    pr[1] = 0;
    for(ll i=4; i<=n; i+=2) pr[i] = 0;
    for(ll i=3; i*i<=n; i+=2) {
        if(pr[i]) {
            for(ll j=i*i; j<=n; j+=i) pr[j] = 0;
        }
    }
    for(ll i=1; i<=n; i++) if(pr[i]) primes.push_back(i);
}

void primeFactorize(ll n)
{
    for(ll i=0; primes[i]*primes[i]<=n; i++) {
        if(n % primes[i] == 0) {
            while(n % primes[i] == 0) {
                n /= primes[i];
                pfact.push_back(primes[i]);
            }
        }
    }
    if(n > 1) pfact.push_back(n);
}

int main()
{
    ll n;
    cin>>n;
    sieve(n);
    primeFactorize(n);
    for(auto i: pfact) cout<<i<<" ";
    cout<<"\n";
}
