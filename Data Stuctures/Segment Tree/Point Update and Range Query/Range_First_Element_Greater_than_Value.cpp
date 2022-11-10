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
ll query(ll v, ll tl, ll tr, ll l, ll r, ll x)
{
    if(l > tr or r < tl) return -1;
    if(l <= tl and tr <= r) {
        if(st[v] <= x) return -1;
        while(tl != tr) {
            ll tm = (tl + tr) / 2;
            if(st[2*v] > x) {
                v = 2*v;
                tr = tm;
            }
            else {
                v = 2*v+1;
                tl = tm+1;
            }
        }
        return tl;
    }
    ll tm = (tl + tr) / 2;
    ll q = query(2*v, tl, tm, l, r, x);
    if(q != -1) return q;
    return query(2*v+1, tm+1, tr, l ,r, x);
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 3, 5, 10)<<"\n";
    update(1, 1, n, 2, 50);
    cout<<query(1, 1, n, 2, 5, 26)<<"\n";
    update(1, 1, n, 3, 100);
    cout<<query(1, 1, n, 2, 6, 76)<<"\n";
}

/*

6
22 26 18 6 2 12

*/
