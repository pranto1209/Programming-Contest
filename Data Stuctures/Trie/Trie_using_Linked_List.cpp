#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool mark;
    node *nxt[26];
    node(){
        mark=false;
        for(int i=0; i<26; i++) nxt[i]=NULL;
    }
}*root;

void add(string s)
{
    node *now = root;
    for(int i=0; i<s.size(); i++){
        int id=s[i]-'a';
        if(now->nxt[id]==NULL) now->nxt[id] = new node();
        now = now->nxt[id];
    }
    now->mark = true;
}

bool check(string s)
{
    node *now = root;
    for(int i=0; i<s.size(); i++){
        int id=s[i]-'a';
        if(now->nxt[id]==NULL) return false;
        now = now->nxt[id];
    }
    return now->mark;
}
void del(node *now)
{
    for(int i=0; i<26; i++) if(now->nxt[i]) del(now->nxt[i]);
    delete now;
}

int main()
{
    root = new node();
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
    del(root);
}
