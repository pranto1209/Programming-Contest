#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
vector<int>g[maxn], r[maxn], components[maxn];
stack<int>stk;
bool vis[maxn], color[maxn];
int n, e, comp;

void dfs(int u)
{
    color[u]=true;
    for(int i=0; i<g[u].size(); i++){
		int v=g[u][i];
		if(!color[v]){
			dfs(v);
		}
	}
    stk.push(u);
}


void dfsr(int u)
{
    vis[u]=true;
    components[comp].push_back(u);
    for(int i=0; i<r[u].size(); i++){
		int v=r[u][i];
		if(!vis[v]){
			dfsr(v);
		}
	}
}

void kosaraju()
{
    for(int i=1; i<=n; i++){
        if(!color[i]){
            dfs(i);
        }
    }
    while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        if(!vis[u]){
            comp++;
            dfsr(u);
        }
    }
}

int main()
{
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        r[v].push_back(u);
    }
    cout<<endl;

    kosaraju();

    cout<<"There have "<<comp<<" Strongly Connected Components.\n\n";

    cout<<"The Components are: \n";
    for(int i=1; i<=comp; i++){
        for(int j=0; j<components[i].size(); j++){
            cout<<components[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*

7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5

*/
