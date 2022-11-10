#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
vector<int>g[maxn];
int vis[maxn], dis[maxn], parent[maxn];

void path(int v)
{
    if(v!=1) path(parent[v]);
    cout<<v<<" ";
}

void dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(!vis[v]){
            dis[v]=dis[u]+1;
            parent[v]=u;
            dfs(v);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;

    dfs(1);

    for(int i=1; i<=n; i++){
        cout<<"Distance from Source to "<<i<<" = "<<dis[i]<<endl;
    }
    cout<<endl;

    for(int i=1; i<=n; i++){
        cout<<"Path from Source to "<<i<<" = ";
        path(i);
        cout<<endl;
    }
}

/*

10
1 2
1 4
1 3
2 6
3 7
3 8
8 5
5 10
7 9

*/
