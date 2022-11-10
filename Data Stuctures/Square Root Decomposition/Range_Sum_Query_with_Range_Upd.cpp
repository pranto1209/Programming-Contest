#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, len, a[maxn], seg[maxn], b[maxn];
void build()
{
    for(int i=0; i<n; i++) seg[i/len]+=a[i];
}
void update(int l, int r, int val)
{
    while(l<r && l%len!=0){
        seg[l/len]+=val;
        a[l]+=val;
        l++;
    }
    while(l+len<=r){
        seg[l/len]+=len*val;
        b[l/len]+=val;
        l+=len;
    }
    while(l<=r){
        seg[l/len]+=val;
        a[l]+=val;
        l++;
    }
}
int query(int l, int r)
{
    int sum=0;
    while(l<r && l%len!=0){
        sum+=a[l]+b[l/len];
        l++;
    }
    while(l+len<=r){
        sum+=seg[l/len];
        l+=len;
    }
    while(l<=r){
        sum+=a[l]+b[l/len];
        l++;
    }
    return sum;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    len=sqrt(n);

    build();

    cout<<query(4-1, 8-1)<<endl;
    cout<<query(8-1, 13-1)<<endl;
    update(5-1, 10-1, 10);
    cout<<query(4-1, 8-1)<<endl;
    cout<<query(8-1, 13-1)<<endl;
}

/*

13
1 4 2 2 1 1 2 1 3 5 1 2 7

*/
