#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
#define pii pair<int, int>
#define maxn 10000
vector<pii> g[maxn];
int n, e, dis[maxn], parent[maxn];

void path(int v)
{
    if(v!=1) path(parent[v]);
    cout<<v<<" ";
}

void bfs(int s)
{
    deque<int> q;
	for(int i=0; i<=n; i++) dis[i] = inf;
	dis[s] = 0;
	q.push_front(s);
	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		for(int i=0; i<g[u].size(); i++){
			int v = g[u][i].first;
			int w = g[u][i].second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				if(w == 1) q.push_back(v);
				else q.push_front(v);
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
    cout<<endl;
}

/*

9 8
1 2 0
1 3 1
1 4 1
2 5 1
2 6 0
3 7 0
3 8 1
4 9 0

*/
