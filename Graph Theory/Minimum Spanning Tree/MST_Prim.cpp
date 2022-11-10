#include <bits/stdc++.h>
using namespace std;
#define maxn 10000
#define pii pair<int, int>
vector<pii>g[maxn], minEdges;
vector<int>minCost;
int n, e, sum, dis[maxn], vis[maxn], par[maxn];

void path(int v)
{
    if(v != 1) path(par[v]);
    cout<<v<<" ";
}

void primMST(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i=0; i<=n; i++) dis[i] = INT_MAX;
    q.push({0, s});
    while(!q.empty()) {
        pii p = q.top();
        q.pop();
        int u = p.second;
        if(vis[u]) continue;
        vis[u] = 1;
        minCost.push_back(p.first);
        minEdges.emplace_back(par[u], u);
        sum += p.first;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;
            if(!vis[v] and dis[v] > w) {
                dis[v] = w;
                q.push({dis[v], v});
                par[v] = u;
            }
        }
    }
}

int main()
{
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cout<<endl;

    primMST(1);

    cout<<"Edges of Minimum Spanning Tree with Weight: "<<endl;
    for(int i=1; i<n; i++){
        cout<<minEdges[i].first<<"---"<<minEdges[i].second<<" -> "<<minCost[i]<<endl;
    }
    cout<<endl;

    cout<<"Total summation of Minimum Weight: \n"<<sum<<endl;
    cout<<endl;

    for(int i=1; i<=n; i++){
        cout<<"Path from Source to "<<i<<" = ";
        path(i);
        cout<<endl;
    }
    cout<<endl;
}

/*

8 11
1 2 4
1 4 10
1 5 2
2 4 8
2 3 18
3 4 11
4 5 5
4 7 11
4 8 9
6 7 1
6 8 2

*/
