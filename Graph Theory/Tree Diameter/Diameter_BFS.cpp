#include<bits/stdc++.h>
using namespace std;
vector<int>g[10000];
bool vis[10000];
int dis[10000];

void bfs(int source)
{
    queue<int>q;
    vis[source]=true;
    dis[source]=0;
    q.push(source);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++){
            int v=g[u][i];
            if(vis[v]==false){
                vis[v]=true;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int nodes, edges, u, v;
    cout<<"Enter number of Nodes and Edges: "<<endl;
    cin>>nodes>>edges;
    cout<<"Nodes between Edge: "<<endl;
    for(int i=1; i<=edges; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;

    bfs(1);

    int maxdis=0, node1;
    for(int i=1; i<=nodes; i++){
        if(dis[i]>maxdis){
            maxdis=dis[i];
            node1=i;
        }
    }

    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    bfs(node1);

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

12 11
1 2
2 3
2 4
4 5
4 6
1 7
7 8
7 9
7 10
10 11
11 12

*/