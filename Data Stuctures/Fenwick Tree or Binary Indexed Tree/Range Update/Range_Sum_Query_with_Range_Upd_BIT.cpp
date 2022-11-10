#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, a[maxn], bit1[maxn], bit2[maxn];
void update(int *bit, int idx, int val)
{
    for(int i=idx; i<=n; i+=(i&-i)) bit[i]+=val;
}
void update(int l, int r, int val)
{
    update(bit1, l, val);
    update(bit1, r+1, -val);
    update(bit2, l, (val*(l-1)));
    update(bit2, r+1, (-val*r));
}
int query(int *bit, int idx)
{
    int ret=0;
	for(int i=idx; i>0; i-=(i&-i)) ret+=bit[i];
    return ret;
}
int query(int idx)
{
    return query(bit1, idx)*idx - query(bit2, idx);
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
		update(i, i, a[i]);
	}
	cout<<query(2, 5)<<endl;
	cout<<query(4, 8)<<endl;
	update(2, 3, 10);
	cout<<query(2, 5)<<endl;
	cout<<query(4, 8)<<endl;
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
