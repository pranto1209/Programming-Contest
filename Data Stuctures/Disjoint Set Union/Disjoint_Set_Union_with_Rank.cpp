#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int n, e, par[maxn], rnk[maxn];
void make_set()
{
    for(int i=1; i<=n; i++) par[i]=i;
}
int find_rep(int u)
{
    if(par[u]==u) return u;
    return par[u]=find_rep(par[u]);
}
void make_union(int u, int v)
{
    u=find_rep(u);
    v=find_rep(v);
    if(u!=v){
        if(rnk[u]<rnk[v]) swap(u, v);
        par[v] = u;
        if(rnk[u]==rnk[v]) rnk[u]++;
    }
}
int main()
{
    cin>>n>>e;
    make_set();
    cout<<"Nodes between Edge: "<<endl;
    for(int i=1; i<=e; i++){
        int u, v;
        cin>>u>>v;
        make_union(u, v);
    }

    set<int>rep;
    for(int i=1; i<=n; i++){
        rep.insert(find_rep(i));
    }
    cout<<endl;

    cout<<"Number of Set: "<<rep.size()<<endl;

    cout<<"Representative are: \n";
    for(auto i: rep) cout<<i<<" ";
    cout<<endl;
}

/*

6 4
1 2
1 3
4 5
5 6

*/
