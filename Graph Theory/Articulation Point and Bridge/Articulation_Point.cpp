#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
vector<int>g[maxn];
bool vis[maxn], isPoint[maxn];
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
            if(st[u] <= low[v] && u!=1) isPoint[u]=true;
        }
        else{
            low[u] = min(low[u], st[v]);
        }
    }
    if(u==1 && numChildren>1) isPoint[u]=true;
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

    int cnt=0;
    cout<<"Articulation Points are: \n";
    for(int i=1; i<=n; i++){
        if(isPoint[i]){
            cout<<i<<endl;
            cnt++;
        }
    }
    if(cnt==0) cout<<"There have no Articulation Point.\n";
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
