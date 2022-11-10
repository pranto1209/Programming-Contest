#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
	cin>>n;
    ll a[n];
    vector<ll> v;
	for(ll i=0; i<n; i++) cin>>a[i];
	for(ll x=1; x < 1<<n; x++) {
		ll val = 1;
		for(ll i=0; i<n; i++) if((x>>i) & 1) val *= a[i];
        v.push_back(val);
	}
	sort(v.begin(), v.end());
	for(auto i: v) cout<<i<<" ";
	cout<<"\n";
}