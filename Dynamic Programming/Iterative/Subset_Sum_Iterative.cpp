#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int n, w, coin[maxn], dp[maxn];

int subset_sum()
{
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(j-coin[i]>=0) dp[j] = dp[j] + dp[j-coin[i]];
        }
    }
    return dp[w];
}

int main()
{
    cin>>n>>w;
    for(int i=0; i<=w; i++) dp[i]=0;
    for(int i=1; i<=n; i++) cin>>coin[i];
	cout<<subset_sum()<<endl;
}

/*

5 150
5 8 11 15 18

3 5
1 2 3

*/
