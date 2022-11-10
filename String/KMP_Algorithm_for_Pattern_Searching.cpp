#include<bits/stdc++.h>
using namespace std;
vector<int>occurences;
int pi[100000];

void prefix_function(string p)
{
    int j=0;
    for(int i=1; i<p.size(); i++){
        while(j && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) j++;
        pi[i]=j;
    }
}
// O(n)

void kmp(string t, string p)
{
    int j=0;
    for(int i=0; i<t.size(); i++){
        while(j && t[i]!=p[j]) j=pi[j-1];
        if(t[i]==p[j]) j++;
        if(j==p.size()) occurences.push_back(i-j+1);
    }
}

int main()
{
    string text, pattern;
    cin>>text>>pattern;

    prefix_function(pattern);

    kmp(text, pattern);

    cout<<"Values of Prefix Function: ";
    for(int i=0; i<pattern.size(); i++) cout<<pi[i]<<" ";
    cout<<endl;

    if(occurences.size()){
        cout<<"Pattern Found at Index: ";
        for(auto i: occurences) cout<<i<<" ";
        cout<<endl;
    }
    else cout<<"Pattern Not Found!\n";
}
// Time Complexity: O(m+n)
// Space Complexity: O(n)

/*

aabaaab
ab

*/
