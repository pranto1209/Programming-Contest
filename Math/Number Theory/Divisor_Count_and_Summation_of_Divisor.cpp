#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> divisor;

void findDivisor(ll n)
{
    for(ll i=1; i*i<=n; i++) {
        if(i*i == n) divisor.push_back(i);
        else if(n % i == 0) {
            divisor.push_back(i);
            divisor.push_back(n/i);
        }
    }
    sort(divisor.begin(), divisor.end());
}

ll countDivisor(ll n)
{
    ll cnt=0;
    for(ll i=1; i*i<=n; i++) {
        if(i*i == n) cnt++;
        else if(n % i == 0) cnt += 2;
    }
    return cnt;
}

ll divisorSum(ll n)
{
    ll sum = 0;
    for(ll i=1; i*i<=n; i++) {
        if(i*i == n) sum += i;
        else if(n%i==0) sum += (i + n/i);
    }
    return sum;
}

int main()
{
    ll n;
    cin>>n;

    findDivisor(n);

    for(auto i: divisor) cout<<i<<" ";
    cout<<"\n";

    ll cntd = countDivisor(n);

    cout<<"Number of Divisor: "<<cntd<<"\n";

    ll sumd = divisorSum(n);

    cout<<"Summation of Divisor: "<<sumd<<"\n";
}

