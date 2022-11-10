#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define pii pair<int, int>
int a[maxn];
pii st[4*maxn];
pii combine(pii a, pii b)
{
    if(a.first>b.first) return a;
    if(b.first>a.first) return b;
    return {a.first, a.second+b.second};
}
void build(int v, int tl, int tr)
{
    if(tl==tr) {st[v]={a[tl], 1}; return;}
    int tm=(tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = combine(st[2*v], st[2*v+1]);
}
void update(int v, int tl, int tr, int pos, int val)
{
    if(tl==tr) {st[v]={val, 1}; return;}
    int tm=(tl+tr)/2;
    if(pos<=tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    st[v] = combine(st[2*v], st[2*v+1]);
}
pii query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return {INT_MIN, 0};
    if(tl>=l && tr<=r) return st[v];
    int tm=(tl+tr)/2;
    return combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 2, 5).first<<" "<<query(1, 1, n, 2, 5).second<<endl;
    update(1, 1, n, 2, 50);
    cout<<query(1, 1, n, 2, 5).first<<" "<<query(1, 1, n, 2, 5).second<<endl;
    update(1, 1, n, 3, 50);
    cout<<query(1, 1, n, 2, 6).first<<" "<<query(1, 1, n, 2, 6).second<<endl;
}

/*

6
26 26 8 26 2 12

*/
