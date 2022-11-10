#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn], st[4*maxn];
void build(int v, int tl, int tr)
{
    if(tl==tr) {st[v]=a[tl]; return;}
    int tm=(tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = max(st[2*v], st[2*v+1]);
}
void update(int v, int tl, int tr, int pos, int val)
{
    if(tl==tr) {st[v]=val; return;}
    int tm=(tl+tr)/2;
    if(pos<=tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    st[v] = max(st[2*v], st[2*v+1]);
}
int query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return INT_MIN;
    if(tl>=l && tr<=r) return st[v];
    int tm=(tl+tr)/2;
    return max(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 2, 5)<<endl;
    update(1, 1, n, 2, 50);
    cout<<query(1, 1, n, 2, 5)<<endl;
    update(1, 1, n, 3, 100);
    cout<<query(1, 1, n, 2, 6)<<endl;
}

/*

6
-222 26 -18 6 2 12

*/
