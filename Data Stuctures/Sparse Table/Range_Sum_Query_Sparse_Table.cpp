#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define k 20
ll st[maxn][k];
int n, a[maxn];
void build()
{
    for(int i=0; i<n; i++) st[i][0] = a[i];
    for(int j=1; (1<<j) <= n; j++)
        for(int i=0; i+(1<<j) <= n; i++)
            st[i][j] = st[i][j-1] + st[i+(1<<(j-1))][j-1];
}
ll query(int l, int r)
{
    ll sum = 0;
    for(int j=k; j>=0; j--){
        if(1<<j <= r-l+1){
            sum += st[l][j];
            l += 1<<j;
        }
    }
    return sum;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    build();

    cout<<query(1-1, 11-1)<<endl;
    cout<<query(2-1, 5-1)<<endl;
    cout<<query(4-1, 8-1)<<endl;
}

/*

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
