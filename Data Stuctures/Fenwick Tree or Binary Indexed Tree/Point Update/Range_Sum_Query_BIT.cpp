#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, a[maxn], bit[maxn];
void update(int idx, int val)
{
    for(int i=idx; i<=n; i+=(i&-i)) bit[i]+=val;
}
int query(int idx)
{
    int ret=0;
	for(int i=idx; i>0; i-=(i&-i)) ret+=bit[i];
    return ret;
}
int query(int l, int r)
{
    return query(r) - query(l-1);
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		update(i, a[i]);
	}
	cout<<query(2, 5)<<endl;
	cout<<query(4, 8)<<endl;
	update(4, 10);
	cout<<query(2, 5)<<endl;
	cout<<query(4, 8)<<endl;
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
