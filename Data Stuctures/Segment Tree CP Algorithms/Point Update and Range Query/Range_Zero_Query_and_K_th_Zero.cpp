#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn], st[4*maxn];
void build(int v, int tl, int tr)
{
    if(tl==tr) {st[v]=!a[tl]; return;}
    int tm=(tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = st[2*v] + st[2*v+1];
}
void update(int v, int tl, int tr, int pos, int val)
{
    if(tl==tr) {st[v]=!val; return;}
    int tm=(tl+tr)/2;
    if(pos<=tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    st[v] = st[2*v] + st[2*v+1];
}
int query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(tl>=l && tr<=r) return st[v];
    int tm=(tl+tr)/2;
    return query(2*v, tl, tm, l, min(r, tm)) + query(2*v+1, tm+1, tr, max(l, tm+1), r);
}
int find_kth(int v, int tl, int tr, int k)
{
    if(k>st[v]) return -1;
    if(tl==tr) return tl;
    int tm=(tl+tr)/2;
    if(st[2*v]>=k) return find_kth(2*v, tl, tm, k);
    else return find_kth(2*v+1, tm+1, tr, k-st[2*v]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 2, 8)<<endl;
    update(1, 1, n, 2, 0);
    cout<<query(1, 1, n, 2, 5)<<endl;
    update(1, 1, n, 3, 10);
    cout<<query(1, 1, n, 2, 6)<<endl;
    cout<<endl;

    cout<<find_kth(1, 1, n, 3)<<endl;
}

/*

6
0 2 0 5 0 9

*/
