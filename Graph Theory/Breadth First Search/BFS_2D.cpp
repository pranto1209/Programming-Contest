#include<bits/stdc++.h>
#define maxn 1000
#define pii pair<int, int>
using namespace std;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int row, col, vis[maxn][maxn], cell[maxn][maxn], dis[maxn][maxn];

void bfs(int sx, int sy)
{
    queue<pii> q;
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	q.push({sx, sy});
	while(!q.empty()) {
		pii top = q.front();
		q.pop();
		for(int k=0; k<4; k++) {
			int tx = top.first + fx[k];
			int ty = top.second + fy[k];
			if(tx >= 0 and tx < row and ty >= 0 and ty < col and cell[tx][ty] != -1 and !vis[tx][ty]) {
				vis[tx][ty] = 1;
				dis[tx][ty] = dis[top.first][top.second] + 1;
				q.push({tx, ty});
			}
		}
	}
}

int main()
{
    int x, y;
    cout<<"Enter number of Row and Column: ";
    cin>>row>>col;

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin>>cell[i][j];
		}
	}

    memset(vis, 0, sizeof vis);
	bfs(0, 0);

    cout<<"Enter Position of (x, y) to Find the Distance from Source: ";
    cin>>x>>y;
	cout<<dis[x][y]<<endl;

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*

5 5
1 1 -1 1 1
-1 1 1 1 1
-1 1 1 1 -1
-1 1 1 1 1
1 1 -1 1 1

*/



