#include <bits/stdc++.h>
using namespace std;
#define maxn 10000
vector<int> g[maxn];
int vis[maxn], dis[maxn], parent[maxn];

void path(int v)
{
    if(v!=1) path(parent[v]);
    cout<<v<<" ";
}

void bfs(int s)
{
    queue<int> q;
    vis[s] = 1;
    dis[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                parent[v] = u;
                q.push(v);
            }
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
        //g[v].push_back(u);
    }
    cout<<endl;

    bfs(1);

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

10 13
1 2
1 4
1 3
2 6
3 7
3 8
4 7
5 10
6 10
7 9
7 8
8 5
9 10

*/
