#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, a[maxn];
vector<int>lt(maxn, INT_MIN), rt(maxn, INT_MIN);
void update(int idx, int val)
{
    for(int i=idx; i<=n; i+=(i&-i)) lt[i] = max(lt[i], val);
    for(int i=idx; i>0; i-=(i&-i)) rt[i] = max(rt[i], val);
    a[idx] = val;
}
int query(int l, int r)
{
    int i, res=INT_MIN;
    for(i=l; i+(i&-i)<=r; i+=(i&-i)) res = max(res, rt[i]);
    for(i=r; i-(i&-i)>=l; i-=(i&-i)) res = max(res, lt[i]);
    res = max(res, a[i]);
    return res;
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		update(i, a[i]);
	}
	cout<<query(2, 5)<<endl;
    update(2, 50);
    cout<<query(2, 5)<<endl;
    update(3, 100);
    cout<<query(2, 6)<<endl;
}

/*

6
22 26 -18 6 2 12

*/
