#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
int a[maxn], st[4*maxn], lazy[4*maxn];

void push(int v, int tl, int tr)
{
    if(lazy[v]){
        int tm = (tl+tr)/2;
        st[2*v] += (tm-tl+1)*lazy[v];
        lazy[2*v] += lazy[v];
        st[2*v+1] += (tr-tm)*lazy[v];
        lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
}

void build(int v, int tl, int tr)
{
    if(tl==tr) {st[v]=a[tl]; return;}
    int tm=(tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = st[2*v] + st[2*v+1];
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l>r) return;
    if(tl>=l && tr<=r){
        st[v] += (tr-tl+1)*val;
        lazy[v] += val;
        return;
    }
    push(v, tl, tr);
    int tm=(tl+tr)/2;
    update(2*v, tl, tm, l, min(r, tm), val);
    update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
    st[v] = st[2*v] + st[2*v+1];
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(tl>=l && tr<=r) return st[v];
    push(v, tl ,tr);
    int tm=(tl+tr)/2;
    return query(2*v, tl, tm, l, min(r, tm)) + query(2*v+1, tm+1, tr, max(l, tm+1), r);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 2, 5)<<endl;
	cout<<query(1, 1, n, 1, 4)<<endl;
	update(1, 1, n, 4, 6, 10);
	cout<<query(1, 1, n, 2, 6)<<endl;
	cout<<query(1, 1, n, 1, 4)<<endl;
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/

