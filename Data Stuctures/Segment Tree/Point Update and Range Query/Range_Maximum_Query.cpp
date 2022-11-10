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
    st[v] = max(st[2*v], st[2*v+1]);
}
void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if(tl == tr) {st[v] = val; return;}
    ll tm = (tl + tr) / 2;
    if(pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    st[v] = max(st[2*v], st[2*v+1]);
}
ll query(int v, int tl, int tr, int l, int r)
{
    if(l > tr or r < tl) return LLONG_MIN;
    if(l <= tl and tr <= r) return st[v];
    ll tm = (tl + tr) / 2;
    return max(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 2, 5)<<"\n";
    update(1, 1, n, 2, 50);
    cout<<query(1, 1, n, 2, 5)<<"\n";
    update(1, 1, n, 3, 100);
    cout<<query(1, 1, n, 2, 6)<<"\n";
}

/*

6
-222 26 -18 6 2 12

*/
