#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, a[maxn], st[maxn][20];
void build()
{
    for(int i=0; i<n; i++) st[i][0] = a[i];
    for(int j=1; (1<<j) <= n; j++)
        for(int i=0; i+(1<<j) <= n; i++)
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}
int query(int l, int r)
{
    int j = log2(r-l+1);
	int ans = max(st[l][j], st[r-(1<<j)+1][j]);
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    build();

    cout<<query(1-1, 6-1)<<endl;
    cout<<query(2-1, 5-1)<<endl;
    cout<<query(4-1, 6-1)<<endl;
}

/*

6
22 26 -18 6 2 12

*/
