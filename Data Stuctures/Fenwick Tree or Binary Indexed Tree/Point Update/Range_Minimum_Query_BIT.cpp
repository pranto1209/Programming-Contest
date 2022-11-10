#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, a[maxn];
vector<int>lt(maxn, INT_MAX), rt(maxn, INT_MAX);
void update(int idx, int val)
{
    for(int i=idx; i<=n; i+=(i&-i)) lt[i] = min(lt[i], val);
    for(int i=idx; i>0; i-=(i&-i)) rt[i] = min(rt[i], val);
    a[idx] = val;
}
int query(int l, int r)
{
    int i, res=INT_MAX;
    for(i=r; i-(i&-i)>=l; i-=(i&-i)) res=min(res, lt[i]);
    for(i=l; i+(i&-i)<=r; i+=(i&-i)) res=min(res, rt[i]);
    res = min(res, a[i]);
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
    update(2, -50);
    cout<<query(2, 5)<<endl;
    update(3, -100);
    cout<<query(2, 6)<<endl;
}

/*

6
-222 26 -18 6 2 12

*/
