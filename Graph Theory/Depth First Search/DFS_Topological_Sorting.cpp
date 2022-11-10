#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int>g[maxn], order;
vector<pair<int, int>>treeEdge, backEdge;
int color[maxn], st[maxn], fn[maxn];
int dt;

void dfs(int u)
{
	st[u] = ++dt;
	color[u]=GREY;
	for(int i=0; i<g[u].size(); i++){
		int v=g[u][i];
		if(color[v]==WHITE){
            treeEdge.push_back({u, v});
			dfs(v);
		}
		else if(color[v]==GREY){
            backEdge.push_back({u, v});
		}
	}
	order.push_back(u);
	color[u]=BLACK;
	fn[u] = ++dt;
}

int main()
{
    int n, e;
    cin>>n>>e;
	for(int i=1; i<=e; i++){
        int u, v;
		cin>>u>>v;
		g[u].push_back(v);
	}
    cout<<endl;

	for(int i=1; i<=n; i++){
		if(color[i]==WHITE){
			dfs(i);
		}
	}

	if(backEdge.size()){
	    cout<<"There have "<<backEdge.size()<<" Back Edge.\nSo There have Cycle in Graph.\nThe Back Edge is: ";
        for(int i=0; i<backEdge.size(); i++){
            cout<<backEdge[i].first<<" "<<backEdge[i].second<<endl;
        }
        return 0;
	}

	for(int i=1; i<=n; i++){
		cout<<"Node "<<i<<" -> Starting Time: "<<st[i]<<" and Finishing Time: "<<fn[i]<<endl;
	}
	cout<<endl;

    reverse(order.begin(), order.end());
    for(int i=0; i<order.size(); i++){
        cout<<i+1 <<" > " <<order[i]<<endl;
	}
}

/*

4 4
2 1
2 3
3 4
1 4


5 5
1 2
2 4
2 3
4 5
5 1

*/
