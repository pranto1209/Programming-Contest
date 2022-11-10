#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
#define inf 1000000000
vector< pair<int, int> >g[maxn];
int dis[maxn], parent[maxn];
int n, e, neg_cycle, updated;

void path(int v)
{
    if(v!=1) path(parent[v]);
    cout<<v<<" ";
}

void bellman_ford(int s)
{
    for(int i=0; i<=n; i++) dis[i]=inf;
	dis[s]=0;
    for(int k=1; k<=n; k++){
        updated=0;
        for(int u=1; u<=n; u++){
            for(int i=0; i<g[u].size(); i++){
                int v=g[u][i].first;
                int w=g[u][i].second;
                if(dis[u]+w < dis[v]){
                    dis[v]=dis[u]+w;
                    parent[v]=u;
                    updated=1;
                }
            }
        }
        if(!updated) break;
        else if(k==n && updated) neg_cycle=1;
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

    bellman_ford(1);

    if(neg_cycle){
        cout<<"There have Negative Cycle in Graph.\n";
        return 0;
    }

    for(int i=1; i<=n; i++){
        cout<<"Distance from Source to "<<i<<" = "<<dis[i]<<endl;
    }
    cout<<endl;

    for(int i=1; i<=n; i++){
        cout<<"Path from Source to "<<i<<" = ";
        path(i);
        cout<<endl;
    }
    cout<<endl;
}

/*

6 6
1 3 2
1 4 4
2 3 10
3 4 1
4 5 7
4 6 5


5 6
1 2 1
2 3 2
2 4 5
3 4 1
3 5 -3
4 5 2

*/
