#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
#define inf 1000000
int n, w, coin[maxn], dp[maxn], dir[maxn];

void value(int v)
{
    if(v==0) return;
    int u = dir[v];
    cout<<coin[u]<<" ";
    value(v-coin[u]);
}

int coin_change()
{
    dp[0]=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(j-coin[i]>=0){
                if(dp[j] > 1 + dp[j-coin[i]]){
                    dp[j] = 1 + dp[j-coin[i]];
                    dir[j] = i;
                }
            }
        }
    }
    return dp[w];
}

int main()
{
    cin>>n>>w;
    for(int i=0; i<=w; i++) dp[i]=inf, dir[i]=-1;
    for(int i=1; i<=n; i++) cin>>coin[i];
	cout<<coin_change()<<endl;
	if(dir[w]!=-1) value(w);
}

/*

5 150
5 8 11 15 18

4 18
2 3 6 7

3 5
1 2 3

*/
