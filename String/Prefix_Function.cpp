#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int pi[maxn];

void prefix_function(string p)
{
    int j=0;
    for(int i=1; i<p.size(); i++){
        while(j && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) j++;
        pi[i]=j;
    }
}

int main()
{
    string pattern;
    cin>>pattern;

    prefix_function(pattern);

    cout<<"Values of Prefix Function: ";
    for(int i=0; i<pattern.size(); i++) cout<<pi[i]<<" ";
}

/*

aabaaab

*/
