#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
vector<ll> primes, pr(maxn>>1, 1);

void sieve(ll n)
{
    for(ll i=3; i*i<=n; i+=2) {
        if(pr[i>>1]) {
            for(ll j=i*i; j<=n; j+=i+i)
                pr[j>>1] = 0;
        }
    }
    primes.push_back(2);
    for(ll i=3; i<=n; i+=2) if(pr[i>>1]) primes.push_back(i);
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
