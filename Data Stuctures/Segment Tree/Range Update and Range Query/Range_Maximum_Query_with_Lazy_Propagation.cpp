#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn], st[4*maxn], lazy[4*maxn];
void push(int v, int tl, int tr)
{
    if(lazy[v]){
        st[v] = lazy[v];
        if(tl!=tr){
            lazy[2*v] = lazy[v];
            lazy[2*v+1] = lazy[v];
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
    st[v] = max(st[2*v], st[2*v+1]);
}
void update(int v, int tl, int tr, int l, int r, int val)
{
    push(v, tl, tr);
    if(l>tr || r<tl) return;
    if(l<=tl && tr<=r){
        st[v] = val;
        if(tl!=tr){
            lazy[2*v] = val;
            lazy[2*v+1] = val;
        }
        return;
    }
    int tm=(tl+tr)/2;
    update(2*v, tl, tm, l, r, val);
    update(2*v+1, tm+1, tr, l, r, val);
    st[v] = max(st[2*v], st[2*v+1]);
}
int query(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if(l>tr || r<tl) return INT_MIN;
    if(l<=tl && tr<=r) return st[v];
    int tm=(tl+tr)/2;
    return max(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1, 1, n);

    cout<<query(1, 1, n, 2, 5)<<endl;
	cout<<query(1, 1, n, 4, 9)<<endl;
	update(1, 1, n, 3, 6, 10);
	cout<<query(1, 1, n, 2, 5)<<endl;
	cout<<query(1, 1, n, 4, 9)<<endl;
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
