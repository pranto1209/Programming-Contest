#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
#define  maxn 1000
int n, e, g[maxn][maxn], parent[maxn][maxn];

void path(int i, int j)
{
    vector<int>v;
    v.push_back(i);
    while(i!=j){
        i=parent[i][j];
        v.push_back(i);
    }
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}

void floyd_warshall()
{
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                    parent[i][j] = parent[i][k];
                }
            }
        }
    }
}

int main()
{
    int u, v, w;
    cin>>n>>e;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) g[i][j]=0;
            else g[i][j]=inf;
            parent[i][j]=j;
        }
    }
    for(int i=1; i<=e; i++){
        cin>>u>>v>>w;
        g[u][v]=w;
        //g[v][u]=w;
    }
    cout<<endl;

    floyd_warshall();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(g[i][j]==inf) cout<<"inf ";
            else cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<"Path from "<<i<<" to "<<j<<" = ";
            if(g[i][j]!=inf) path(i, j);
            else cout<<"No Path\n";
        }
    }
}

/*

4 6
1 2 3
2 1 2
2 3 2
3 2 5
4 3 8
4 1 20

*/
