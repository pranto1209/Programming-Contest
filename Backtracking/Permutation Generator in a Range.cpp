#include <bits/stdc++.h>
using namespace std;
int a, b, pos[1000], vis[1000];

void backtrack(int idx)
{
    if(idx == b+1) {
        for(int i=a; i<=b; i++) cout<<pos[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=a; i<=b; i++){
        if(!vis[i]){
            vis[i] = 1;
            pos[idx] = i;
            backtrack(idx+1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin>>a>>b;
    backtrack(a);
}
