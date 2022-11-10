#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int n, a[maxn], dp[maxn], dir[maxn];

void path(int v)
{
    vector<int>val;
    while(v!=-1) {
        val.push_back(a[v]);
        v=dir[v];
    }
    reverse(val.begin(), val.end());
    for(int i: val) cout<<i<<" ";
}

void lis()
{
    for(int i=0; i<=n; i++) dp[i]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[i]>a[j] && 1+dp[j] > dp[i]){
                dp[i] = 1+dp[j];
                dir[i] = j;
            }
        }
    }
}

int main()
{
    memset(dir, -1, sizeof(dir));
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    lis();

    int ans=0, pos;
    for(int i=1; i<=n; i++){
        if(dp[i]>ans){
            ans = dp[i];
            pos = i;
        }
    }
    cout<<"Lenght of LIS is: "<<ans<<endl;
    path(pos);
}

/*

7
5 0 9 2 7 3 4

10
8 1 9 8 3 4 6 1 5 2

*/
