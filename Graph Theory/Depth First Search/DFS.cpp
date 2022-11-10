#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
vector<int>g[maxn];
int vis[maxn];

void dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;

    dfs(1);

    for(int i=1; i<=n; i++){
        if(vis[i]) cout<<"Node "<<i<<" is visited.\n";
        else cout<<"Node "<<i<<" is not visited.\n";
    }
}

/*

7 6
1 2
1 5
2 4
2 3
4 5
6 7

*/
