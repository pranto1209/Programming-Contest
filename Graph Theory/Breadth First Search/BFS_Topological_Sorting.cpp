#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
vector<int>g[maxn], order;
int indegree[maxn];
int n, e;

void top_sort()
{
    queue<int>q;
    for(int i=1; i<=n; i++) {
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		order.push_back(u);
		q.pop();
		for(int i=0; i<g[u].size(); i++){
			int v=g[u][i];
			indegree[v]--;
			if(indegree[v]==0){
				q.push(v);
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
		indegree[v]++;
    }
    cout<<endl;

    top_sort();

    for(int i=1; i<=n; i++){
        if(indegree[i]!=0){
            cout<<"There have Cycle in Graph\n";
            return 0;
        }
	}

	for(int i=0; i<order.size(); i++){
		cout<<i+1 <<" -> " <<order[i]<<endl;
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

3 4
1 2
2 3
1 3
3 1

*/
