#include <bits/stdc++.h>
using namespace std;
int n, pos[1000], vis[1000];

void backtrack(int idx)
{
    if(idx == n) {
        for(int i=0; i<n; i++) cout<<pos[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(!vis[i]) {
            vis[i] = 1;
            pos[idx] = i;
            backtrack(idx+1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin>>n;
    backtrack(0);
}
