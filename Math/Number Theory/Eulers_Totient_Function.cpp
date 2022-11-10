#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll phi(ll n)
{
    ll ret = n;
    for(ll i=2; i*i<=n; i++) {
        if(n % i == 0) {
            while(n%i == 0) {
                n /= i;
            }
            ret -= ret/i;
        }
    }
    if(n>1) ret -= ret/n;
    return ret;
}

int main()
{
    ll n;
    cin>>n;
    cout<<phi(n)<<"\n";
}
