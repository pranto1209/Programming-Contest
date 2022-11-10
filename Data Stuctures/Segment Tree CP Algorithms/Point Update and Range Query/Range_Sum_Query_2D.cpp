#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int n, m, a[maxn][maxn], st[maxn][maxn];
void build_2d(int vx, int x1, int x2, int vy, int tl, int tr)
{
    if(tl==tr){
        if(x1==x2) st[vx][vy] = a[x1][tl];
        else st[vx][vy] = st[2*vx][vy] + st[2*vx+1][vy];
    }
    else{
        int tm=(tl+tr)/2;
        build_2d(vx, x1, x2, 2*vy, tl, tm);
        build_2d(vx, x1, x2, 2*vy+1, tm+1, tr);
        st[vx][vy] = st[vx][2*vy] + st[vx][2*vy+1];
    }
}
void build(int v, int tl, int tr)
{
    if(tl != tr){
        int tm=(tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
    }
    build_2d(v, tl, tr, 1, 1, m);
}
void update_2d(int vx, int x1, int x2, int vy, int tl, int tr, int x, int y, int val)
{
    if(tl==tr){
        if(x1==x2) st[vx][vy] += val;
        else st[vx][vy] = st[2*vx][vy] + st[2*vx+1][vy];
    }
    else{
        int tm=(tl+tr)/2;
        if(y<=tm) update_2d(vx, x1, x2, 2*vy, tl, tm, x, y, val);
        else update_2d(vx, x1, x2, 2*vy+1, tm+1, tr, x, y, val);
        st[vx][vy] = st[vx][2*vy] + st[vx][2*vy+1];
    }
}
void update(int v, int tl, int tr, int x, int y, int val)
{
    if(tl != tr){
        int tm=(tl+tr)/2;
        if(x<=tm) update(2*v, tl, tm, x, y, val);
        else update(2*v+1, tm+1, tr, x, y, val);
    }
    update_2d(v, tl, tr, 1, 1, m, x, y, val);
}
int query_2d(int vx, int vy, int tl, int tr, int y1, int y2)
{
    if(y1>y2) return 0;
    if(tl>=y1 && tr<=y2) return st[vx][vy];
    int tm=(tl+tr)/2;
    return query_2d(vx, 2*vy, tl, tm, y1, min(y2, tm)) + query_2d(vx, 2*vy+1, tm+1, tr, max(y1, tm+1), y2);
}
int query(int v, int tl, int tr, int x1, int x2, int y1, int y2)
{
    if(x1>x2) return 0;
    if(tl>=x1 && tr<=x2) return query_2d(v, 1, 1, m, y1, y2);
    int tm=(tl+tr)/2;
    return query(2*v, tl, tm, x1, min(x2, tm), y1, y2) + query(2*v+1, tm+1, tr, max(x1, tm+1), x2, y1, y2);
}
int sum_query(int v, int tl, int tr, int x1, int y1, int x2, int y2)
{
    return query(v, tl, tr, x1, x2, y1, y2);
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];

    build(1, 1, n);

	cout<<sum_query(1, 1, n, 2, 3, 4, 4)<<endl;
	update(1, 1, n, 2, 3, 10);
	cout<<sum_query(1, 1, n, 2, 3, 4, 4)<<endl;
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
