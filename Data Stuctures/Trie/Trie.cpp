#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
int nxt[maxn][26];
int node = 1;
bool mark[maxn];

void add(string s)
{
    int now=0;
    for(int i=0; i<s.size(); i++){
        int id=s[i]-'a';
        if(nxt[now][id]==0) nxt[now][id]=node++;
        now=nxt[now][id];
    }
    mark[now]=true;
}

bool check(string s)
{
    int now=0;
    for(int i=0; i<s.size(); i++){
        int id=s[i]-'a';
        if(nxt[now][id]==0) return false;
        now=nxt[now][id];
    }
    return mark[now] ;
}

int main()
{
    int n, q;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        add(s);
    }
    cin>>q;
    for(int i=0; i<q; i++){
        string s;
        cin>>s;
        if(check(s)) puts("Found");
        else puts("Not Found");
    }
}

/*

5
algo
algea
also
tom
to

*/

