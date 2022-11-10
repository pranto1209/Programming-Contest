#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
#define pii pair<int, int>
vector<pair<int, pii>>g;
vector<pii>minEdges;
vector<int>minCost;
int n, e, sum, par[maxn];

void make_set()
{
    for(int i=1; i<=n; i++) par[i]=i;
}

int find_rep(int u)
{
    if(par[u]==u) return u;
    return par[u] = find_rep(par[u]);
}

bool make_union(int u, int v)
{
    u = find_rep(u);
    v = find_rep(v);
    if(u!=v){
        par[v]=u;
        return true;
    }
    return false;
}

void kruskalMST()
{
    for(int i=0; i<g.size(); i++){
        int u = g[i].second.first;
        int v = g[i].second.second;
        int w = g[i].first;
        bool f = make_union(u, v);
        if(f){
            minCost.push_back(w);
            minEdges.emplace_back(u, v);
            sum+=w;
        }
    }
}

int main()
{
    cin>>n>>e;

    make_set();

    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.push_back({w, {u, v}});
    }
    cout<<endl;

    sort(g.begin(), g.end());

    kruskalMST();

    cout<<"Edges of Minimum Spanning Tree with Weight: "<<endl;
    for(int i=0; i<minCost.size(); i++){
        cout<<minEdges[i].first<<"---"<<minEdges[i].second<<" -> "<<minCost[i]<<endl;
    }
    cout<<endl;

    cout<<"Total summation of Minimum Weight: \n"<<sum<<endl<<endl;

    cout<<"Representative is: \n"<<find_rep(1)<<endl;
}

/*

5 7
1 2 7
1 3 4
1 4 1
2 4 8
2 5 6
3 4 3
4 5 6

*/
