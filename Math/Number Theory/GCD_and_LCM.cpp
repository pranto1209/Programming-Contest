#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a,b);
}

int main()
{
    ll a, b;
    cin>>a>>b;
    cout<<"GCD: "<<gcd(a, b)<<"\n";
    cout<<"LCM: "<<lcm(a, b)<<"\n";
}
