#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn], st[4*maxn], lazy[4*maxn];
void push(int v, int tl, int tr)
{
    if(lazy[v]){
        if(tl==tr) st[v] = max(st[v], lazy[v]);
        else if(tl!=tr){
            lazy[2*v] = max(lazy[2*v], lazy[v]);
            lazy[2*v+1] = max(lazy[2*v+1], lazy[v]);
        }
        lazy[v] = 0;
    }
}
void build(int v, int tl, int tr)
{
    if(tl==tr) {st[v]=a[tl]; return;}
    int tm=(tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
}
void update(int v, int tl, int tr, int l, int r, int val, int fl)
{
    push(v, tl, tr);
    if(l>tr || r<tl) return;
    if(l<=tl && tr<=r){
        if(fl==1) st[v] = val;
        else if(fl==2){
            st[v] = max(st[v], val);
            if(tl!=tr){
                lazy[2*v] = max(lazy[2*v], val);
                lazy[2*v+1] = max(lazy[2*v], val);
            }
        }
        return;
    }
    int tm=(tl+tr)/2;
    update(2*v, tl, tm, l, r, val, fl);
    update(2*v+1, tm+1, tr, l, r, val, fl);
}
int query(int v, int tl, int tr, int pos)
{
    push(v, tl, tr);
    if(tl==tr) return st[v];
    int tm=(tl+tr)/2;
    if(pos<=tm) return query(2*v, tl, tm, pos);
    else return query(2*v+1, tm+1, tr, pos);
}
int main()
{
    int n, q;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    cin>>q;
    while(q--){
        int fl, p, x;
        cin>>fl;
        if(fl==1){
            cin>>p>>x;
            update(1, 1, n, p, p, x, fl);
        }
        else{
            cin>>x;
            update(1, 1, n, 1, n, x, fl);
        }
    }
    for(int i=1; i<=n; i++) cout<<query(1, 1, n, i)<<" ";
}
