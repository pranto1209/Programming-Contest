#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, a[maxn], bit[maxn];
void update(int idx, int val)
{
    for(int i=idx; i<=n; i+=(i&-i)) bit[i]+=val;
}
void update(int l, int r, int val)
{
    update(l, val);
    update(r+1, -val);
}
int query(int idx)
{
    int ret=0;
	for(int i=idx; i>0; i-=(i&-i)) ret+=bit[i];
    return ret;
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++){
        cin>>a[i];
        update(i, i, a[i]);
	}
	cout<<query(5)<<endl;
	update(2, 5, 10);
	cout<<query(5)<<endl;
	update(2, 5, 7);
	cout<<query(2)<<endl;
	cout<<query(5)<<endl;
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
