#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
vector<int>g[maxn];
stack<int>stk;

void euler_tour(int u)
{
    for(int v: g[u]){
        auto p=find(g[u].begin(), g[u].end(), v);
        g[u].erase(p);
        euler_tour(v);
    }
    stk.push(u);
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    euler_tour(1);

    while(!stk.empty()){
        cout<<stk.top()<<" -> ";
        stk.pop();
    }
}

/*

5 6
1 2
2 3
2 4
3 1
4 5
5 2

*/
