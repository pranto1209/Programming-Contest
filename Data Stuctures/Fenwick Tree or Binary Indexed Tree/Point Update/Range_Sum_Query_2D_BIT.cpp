#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int n, m, a[maxn][maxn], bit[maxn][maxn];
void update(int x, int y, int value)
{
    for(int i=x; i<=n; i+=(i&-i))
		for(int j=y; j<=m; j+=(j&-j))
			bit[i][j]+=value;
}
int query(int x, int y)
{
    int ret=0;
	for(int i=x; i>0; i-=(i&-i))
		for(int j=y; j>0; j-=(j&-j))
			ret+=bit[i][j];
    return ret;
}
int query(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
			update(i, j, a[i][j]);
		}
	}

	cout<<query(2, 3, 4, 4)<<endl;
    update(2, 3, 10);
    cout<<query(2, 3, 4, 4)<<endl;
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

*/
