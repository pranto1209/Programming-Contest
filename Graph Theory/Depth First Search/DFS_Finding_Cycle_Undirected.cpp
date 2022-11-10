#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
vector<int>g[maxn];
int color[maxn], parent[maxn];
int n, e, cycle_start, cycle_end;

bool dfs(int u, int par)
{
    color[u]=1;
    for(int v: g[u]) {
        if(v == par) continue;
        if(color[v]==0){
            parent[v] = u;
            if(dfs(v, parent[v])) return true;
        }
        else if(color[v]==1){
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u]=2;
    return false;
}

int main()
{
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;

    memset(parent, -1, sizeof(parent));
    cycle_start = -1;
    for(int u=1; u<=n; u++){
        if(color[u]==0 && dfs(u, parent[u])) break;
    }
    if(cycle_start==-1) cout<<"There have No Cycle"<<endl;
    else{
        vector<int>cycle;
        cycle.push_back(cycle_start);
        for(int v=cycle_end; v!=cycle_start; v=parent[v]) cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout<<"Cycle Found: ";
        for(int v: cycle) cout<<v<<" ";
        cout<<endl;
    }
}

/*

7 7
1 2
2 3
3 4
4 5
5 3
3 6
6 7


3 4
3 1
1 3
2 3
1 2

3 4
1 2
2 3
1 3
3 1

*/
