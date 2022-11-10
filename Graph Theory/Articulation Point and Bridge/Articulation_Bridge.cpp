#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
vector<int>g[maxn];
vector<pair<int, int>>isBridge;
bool vis[maxn];
int dt, parent[maxn], st[maxn], low[maxn];

void dfs(int u)
{
    dt++;
    st[u] = low[u] = dt;
    vis[u]=true;
    int numChildren=0;
    for(int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if(v==parent[u]) continue;
        if(!vis[v]){
            numChildren++;
            parent[v]=u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(st[u] < low[v]) isBridge.push_back({u, v});
        }
        else{
            low[u] = min(low[u], st[v]);
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

    cout<<"Articulation Bridges are: \n";
    for(int i=0; i<isBridge.size(); i++){
        cout<<isBridge[i].first<<" "<<isBridge[i].second<<endl;
    }
    if(isBridge.size()==0) cout<<"There have no Articulation Bridge.\n";
}

/*

7 7
1 2
1 3
3 4
3 7
4 5
4 6
6 7

*/
