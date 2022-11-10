#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
ll a[maxn], st[4*maxn];
void build(ll v, ll tl, ll tr)
{
    if(tl == tr) {st[v] = a[tl]; return;}
    ll tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = st[2*v] + st[2*v+1];
}
void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if(tl == tr) {st[v] += val; return;}
    ll tm = (tl + tr) / 2;
    if(pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    st[v] = st[2*v] + st[2*v+1];
}
ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l > tr or r < tl) return 0;
    if(l <= tl and tr <= r) return st[v];
    ll tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 2, 5)<<"\n";
	cout<<query(1, 1, n, 4, 8)<<"\n";
	update(1, 1, n, 4, 10);
	cout<<query(1, 1, n, 2, 5)<<"\n";
	cout<<query(1, 1, n, 4, 8)<<"\n";
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
