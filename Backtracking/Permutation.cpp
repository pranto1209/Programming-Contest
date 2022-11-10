#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> ans;
vector<int> vec;
int n;

void solve(int id)
{
    if(id == n-1) {
        ans.push_back(vec);
        return;
    }

    for(int i=id; i<n; i++) {
        swap(vec[i], vec[id]);
        solve(id+1);
        swap(vec[i], vec[id]);
    }

}

vector<vector<int>> permute(vector<int>& vec) {
    solve(0);
    return ans;
}


int main()
{
    cin>>n;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<vector<int>> ans = permute(vec);

    int cnt = 0;
    for(auto x: ans) {
        cout<<++cnt<<": ";
        for(auto y: x) {
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}
