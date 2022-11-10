#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, len, a[maxn], seg[maxn];
void build()
{
    for(int i=0; i<n; i++) seg[i/len]+=a[i];
}
void update(int idx, int val)
{
    seg[idx/len]+=val;
    a[idx]+=val;
}
int query(int l, int r)
{
    int sum=0;
    while(l<r && l%len!=0){
        sum+=a[l];
        l++;
    }
    while(l+len<=r){
        sum+=seg[l/len];
        l+=len;
    }
    while(l<=r){
        sum+=a[l];
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

    cout<<query(2-1, 6-1)<<endl;
    cout<<query(4-1, 13-1)<<endl;
    update(6-1, 5);
    cout<<query(2-1, 6-1)<<endl;
    cout<<query(4-1, 13-1)<<endl;
}

/*

13
1 4 2 2 1 1 2 1 3 5 1 2 7

*/
