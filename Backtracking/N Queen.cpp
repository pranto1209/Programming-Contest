#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<string>> ans;
int n;

bool check(vector<string> &v, int row, int col) {
    /* Check this row on left side */
    for(int i=0; i<col; i++) if(v[row][i] == 'Q') return false;
    /* Check upper diagonal on left side */
    for(int i=row, j=col; i>=0 and j>=0; i--, j--) if(v[i][j] == 'Q') return false;
    /* Check lower diagonal on left side */
    for(int i=row, j=col; j>=0 and i<n; i++, j--) if(v[i][j] == 'Q') return false;

    return true;
}

void solve(vector<string> &v, int col) {
    if(col >= n) {
        ans.push_back(v);
        return;
    }

    for(int i=0; i<n; i++) {
        if(check(v, i, col)) {
            v[i][col] = 'Q';
            solve(v, col+1);
            v[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> v(n, string(n, '.'));
    solve(v, 0);
    return ans;
}


int main()
{
    cin>>n;
    vector<vector<string>> ans = solveNQueens(n);
    cout<<"\n";

    int cnt = 0;
    for(auto x: ans) {
        cout<<++cnt<<"\n";;
        for(auto y: x) {
            cout<<y<<"\n";
        }
        cout<<"\n";
    }
}
