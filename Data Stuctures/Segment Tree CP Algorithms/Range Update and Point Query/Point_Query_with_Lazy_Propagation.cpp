#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
int a[maxn], st[4*maxn], lazy[4*maxn];

void push(int v)
{
    if(lazy[v]){
        st[2*v] += st[v];
        st[2*v+1] += st[v];
        lazy[2*v] = lazy[2*v+1] = 1;
        lazy[v] = st[v] = 0;
    }
}

void build(int v, int tl, int tr)
{
    if(tl==tr) {st[v]=a[tl]; return;}
    int tm=(tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if(l>r) return;
    if(tl>=l && tr<=r){
        st[v]+=val;
        lazy[v]=1;
        return;
    }
    push(v);
    int tm=(tl+tr)/2;
    update(v*2, tl, tm, l, min(r, tm), val);
    update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
}

int query(int v, int tl, int tr, int pos)
{
    if(tl==tr) return st[v];
    push(v);
    int tm=(tl+tr)/2;
    if(pos<=tm) return query(2*v, tl, tm, pos);
    else return query(2*v+1, tm+1, tr, pos);
}

int main()
{
    int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];

	build(1, 1, n);

	cout<<query(1, 1, n, 5)<<endl;
	update(1, 1, n, 2, 5, 10);

	update(1, 1, n, 3, 6, 5);
	update(1, 1, n, 1, n, 15);

	cout<<query(1, 1, n, 5)<<endl;
	update(1, 1, n, 2, 5, 7);
	cout<<query(1, 1, n, 2)<<endl;
	cout<<query(1, 1, n, 5)<<endl;
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
