#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define pii pair<int, int>
#define maxn 10000
vector<pii>g[maxn];
int n, e, dis[maxn], parent[maxn];

void path(int v)
{
    if(v!=1) path(parent[v]);
    cout<<v<<" ";
}

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
	for(int i=0; i<=n; i++) dis[i] = inf;
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		for(int i=0; i<g[u].size(); i++) {
			int v = g[u][i].first;
			int w = g[u][i].second;
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
				parent[v] = u;
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
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
    cout<<endl;

	dijkstra(1);

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

4 4
1 2 2
1 3 5
2 3 1
3 4 3


6 6
1 3 2
1 4 4
2 3 10
3 4 1
4 5 7
4 6 5

*/
