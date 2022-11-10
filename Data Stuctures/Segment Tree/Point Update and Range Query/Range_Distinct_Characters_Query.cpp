#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
ll st[4*maxn];
void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if(tl == tr) {st[v] = val; return;}
    ll tm = (tl + tr) / 2;
    if(pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    st[v] = st[2*v] | st[2*v+1];
}
ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l > tr or r < tl) return 0;
    if(l <= tl and tr <= r) return st[v];
    ll tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, r) | query(2*v+1, tm+1, tr, l, r);
}
int main()
{
    string s;
    cin>>s;
    ll n = s.size(), q;
    for(ll i=0; i<n; i++) {
        ll p = s[i]-'a';
        p = 1 << p;
        update(1, 1, n, i+1, p);
    }
    cin>>q;
    while(q--) {
        ll x, pos, l, r;
        cin>>x;
        if(x == 1) {
            char c;
            cin>>pos>>c;
            ll p = c-'a';
            p = 1 << p;
            update(1, 1, n, pos, p);
        }
        else {
            cin>>l>>r;
            ll val = query(1, 1, n, l, r);
            ll ans = __builtin_popcount(val);
            cout<<ans<<"\n";
        }
    }
}
