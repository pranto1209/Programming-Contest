#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
const int k=log2(maxn)+1;
vector<int>g[maxn];
int n, dis[maxn], st[maxn][k];

void dfs(int u, int p)
{
	dis[u]=dis[p]+1;
	st[u][0]=p;
	for(int v: g[u]){
		if(v!=p)
            dfs(v, u);
	}
}

void build()
{
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i<=n; i++)
            if(st[i][j-1]!=-1)
                st[i][j] = st[st[i][j-1]][j-1];
}

int lca(int u, int v)
{
	if(dis[u]>dis[v]) swap(u, v);
	int dif=dis[v]-dis[u];
	for(int i=0; (1<<i)<=n; i++) if((dif>>i)&1) v=st[v][i];
	if(u==v) return u;
	for(int i=log2(n); i>=0; i--){
		if(st[u][i] != st[v][i]){
			u=st[u][i];
			v=st[v][i];
		}
	}
	return st[u][0];
}

int main()
{
    memset(st, -1, sizeof st);
	cin>>n;
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;

	dfs(1, 0);

	build();

	int q;
	cin>>q;
	while(q--){
        int u, v;
        cin>>u>>v;
        cout<<lca(u, v)<<endl;
	}
}


/*

10
1 2
1 4
1 3
2 6
3 7
3 8
8 5
5 10
7 9

*/
