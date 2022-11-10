#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
vector<int>g[maxn];
vector< pair<int, int> >treeEdge;
int vis[maxn], st[maxn], fn[maxn];
int dt, freq;

void dfs(int u)
{
    st[u] = ++dt;
    vis[u]=1;
    for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(!vis[v]){
            treeEdge.push_back({u, v});
            dfs(v);
        }
    }
    fn[u] = ++dt;
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

    for(int i=1; i<=n; i++){
		if(!vis[i]){
            dt=0;
            freq++;
			dfs(i);
		}
	}

    cout<<"There have "<<freq<<" Components.\n\n";

    for(int i=1; i<=n; i++){
		cout<<"Node "<<i<<" -> Starting Time: "<<st[i]<<" and Finishing Time: "<<fn[i]<<endl;
	}
	cout<<endl;

	cout<<"DFS Tree Edges: \n";
	for(int i=0; i<treeEdge.size(); i++){
        cout<<treeEdge[i].first<<" "<<treeEdge[i].second<<endl;
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
