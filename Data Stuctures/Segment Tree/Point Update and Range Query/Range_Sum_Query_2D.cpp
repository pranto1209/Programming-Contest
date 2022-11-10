#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1005
ll n, m, a[maxn][maxn], st[maxn][maxn];
void build_2d(ll vx, ll x1, ll x2, ll vy, ll tl, ll tr)
{
    if(tl==tr) {
        if(x1 == x2) st[vx][vy] = a[x1][tl];
        else st[vx][vy] = st[2*vx][vy] + st[2*vx+1][vy];
    }
    else {
        ll tm = (tl + tr) / 2;
        build_2d(vx, x1, x2, 2*vy, tl, tm);
        build_2d(vx, x1, x2, 2*vy+1, tm+1, tr);
        st[vx][vy] = st[vx][2*vy] + st[vx][2*vy+1];
    }
}
void build(ll v, ll tl, ll tr)
{
    if(tl != tr) {
        ll tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
    }
    else build_2d(v, tl, tr, 1, 1, m);
}
void update_2d(ll vx, ll x1, ll x2, ll vy, ll tl, ll tr, ll x, ll y, ll val)
{
    if(tl == tr) {
        if(x1 == x2) st[vx][vy] += val;
        else st[vx][vy] = st[2*vx][vy] + st[2*vx+1][vy];
    }
    else {
        ll tm = (tl+tr) / 2;
        if(y <= tm) update_2d(vx, x1, x2, 2*vy, tl, tm, x, y, val);
        else update_2d(vx, x1, x2, 2*vy+1, tm+1, tr, x, y, val);
        st[vx][vy] = st[vx][2*vy] + st[vx][2*vy+1];
    }
}
void update(ll v, ll tl, ll tr, ll x, ll y, ll val)
{
    if(tl != tr) {
        ll tm = (tl + tr) / 2;
        if(x <= tm) update(2*v, tl, tm, x, y, val);
        else update(2*v+1, tm+1, tr, x, y, val);
    }
    else update_2d(v, tl, tr, 1, 1, m, x, y, val);
}
ll query_2d(ll vx, ll vy, ll tl, ll tr, ll y1, ll y2)
{
    if(y1 > tr or y2 < tl) return 0;
    if(y1 <= tl and tr <= y2) return st[vx][vy];
    ll tm = (tl + tr) / 2;
    return query_2d(vx, 2*vy, tl, tm, y1, y2) + query_2d(vx, 2*vy+1, tm+1, tr, y1, y2);
}
ll query(ll v, ll tl, ll tr, ll x1, ll x2, ll y1, ll y2)
{
    if(x1 > tr or x2 < tl) return 0;
    if(x1 <= tl and tr <= x2) return query_2d(v, 1, 1, m, y1, y2);
    ll tm = (tl + tr) / 2;
    return query(2*v, tl, tm, x1, x2, y1, y2) + query(2*v+1, tm+1, tr, x1, x2, y1, y2);
}
ll sum_query(ll v, ll tl, ll tr, ll x1, ll y1, ll x2, ll y2)
{
    return query(v, tl, tr, x1, x2, y1, y2);
}
int main()
{
    cin>>n>>m;
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=m; j++)
            cin>>a[i][j];

    build(1, 1, n);

	cout<<sum_query(1, 1, n, 2, 3, 4, 4)<<"\n";
	update(1, 1, n, 2, 3, 10);
	cout<<sum_query(1, 1, n, 2, 3, 4, 4)<<"\n";
}

/*

x = row
y = column

5 5
1 2 3 4 5
1 4 5 6 5
1 7 8 9 5
1 10 11 12 5
1 13 14 15 5

4 4
1 2 3 4
5 6 7 8
1 7 5 9
3 0 6 2

*/
