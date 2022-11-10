#include<bits/stdc++.h>
#define inf 1000000
#define pii pair<int, int>
using namespace std;
vector<pii>g[10000];
int dis[10000];
int nodes, edges;

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>>q;
	for(int i=0; i<=nodes; i++) dis[i]=inf;
	dis[source]=0;
	q.push({0,source});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=0; i<g[u].size(); i++){
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(dis[u]+w < dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
        }
	}
}

int main()
{
    int u, v, w;
    cout<<"Enter number of Nodes and Edges: "<<endl;
	cin>>nodes>>edges;
	cout<<"Nodes between Edge: "<<endl;
    for(int i=1; i<=edges; i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
    cout<<endl;

	dijkstra(1);

    int maxdis=0, node1;
    for(int i=1; i<=nodes; i++){
        if(dis[i]>maxdis){
            maxdis=dis[i];
            node1=i;
        }
    }

    memset(dis, 0, sizeof(dis));

    dijkstra(node1);

    int diameter=0, node2;
    for(int i=1; i<=nodes; i++){
        if(dis[i]>diameter){
            diameter=dis[i];
            node2=i;
        }
    }
    cout<<"Diameter between node "<<node1<<" to node "<<node2<<" is: "<<diameter<<endl;
}

/*

6 5
1 2 5
2 3 15
2 4 10
3 5 20
3 6 10

*/
