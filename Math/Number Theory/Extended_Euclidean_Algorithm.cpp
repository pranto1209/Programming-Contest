#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll g = gcd(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return g;
}

int main()
{
	ll a, b, x, y;
    cin>>a>>b;
	ll g = gcd(a, b, x, y);
	cout<<"GCD: "<<g<<"\n";
	cout<<"X: "<<x<<" Y: "<<y<<"\n";
}
