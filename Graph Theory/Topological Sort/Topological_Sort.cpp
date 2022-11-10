#include<bits/stdc++.h>
using namespace std;
vector<int>g[10000];
vector<string>order;
map<string, int>mark;
int indegree[10000];
string parent[10000];
int nodes, edges;

void top_sort()
{
    queue<int>q;
    for(int i=1; i<=nodes; i++) {
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		order.push_back(parent[u]);
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
    string a, b;
    cout<<"Enter number of Edges: "<<endl;
    cin>>nodes>>edges;
    nodes=0;
    cout<<"Nodes between Edge: "<<endl;
    for(int i=1; i<=edges; i++){
        cin>>a>>b;
        if(mark.find(a)==mark.end()){
			mark[a]=++nodes;
			parent[nodes]=a;
		}
		if(mark.find(b)==mark.end()){
			mark[b]=++nodes;
			parent[nodes]=b;
		}
		int u=mark[a];
		int v=mark[b];
		g[u].push_back(v);
		indegree[v]++;
    }

    top_sort();

    for(int i=1; i<=nodes; i++){
        if(indegree[i]!=0){
            cout<<"There have Cycle in Graph\n";
            return 0;
        }
	}

    cout<<endl;
	for(int i=0; i<order.size(); i++){
		cout<<i+1 <<" > " <<order[i]<<endl;
	}
}

/*

6 8
Breakfast Office
Dressup Office
Office Email
Office Dinner
Office Sports
Email Dinner
Email Sports
Dinner Sports

*/
