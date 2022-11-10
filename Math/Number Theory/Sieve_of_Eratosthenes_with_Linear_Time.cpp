#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
ll lp[maxn];
vector<ll> pr;

void sieve(ll n)
{
    for(ll i=2; i<=n; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(ll j=0; j < pr.size() and pr[j] <= lp[i] and i*pr[j] <= n; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    sieve(n);
    for(auto i: pr) cout<<i<<" ";
    cout<<"\n";
    for(ll i=1; i<=n; i++) cout<<lp[i]<<" ";
    cout<<"\n";
}
