#include <bits/stdc++.h>
#define maxn 15
using namespace std;
vector<int>g[maxn];
int n, e, color[maxn];
bool flag;

void bipartite(int s)
{
    queue<int> q;
    color[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: g[u]) {
            if(color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
            else {
                if(color[u] == color[v]) flag = false;
            }
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
        g[v].push_back(u);
    }

    memset(color, -1, sizeof(color));
    flag = true;
    for(int i=0; i<n; i++) {
        if(color[i] == -1) {
            bipartite(i);
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
}

/*

3 2
0 1
1 2



*/
