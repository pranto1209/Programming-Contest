#include<bits/stdc++.h>
using namespace std;
vector<int>occurences;
int z[100000];
void z_function(string s)
{
    int n=s.size(), l=0, r=0;
    for(int i=1; i<n; i++){
        if(i <= r) z[i]=min(r-i+1, z[i-l]);
        while(i+z[i] < n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1 > r) l=i, r=i+z[i]-1;
    }
}
int main()
{
    string t, p, s;
    cin>>t>>p;
    s=p+"#"+t;

    z_function(s);

    for(int i=0; i<s.size(); i++){
        cout<<z[i]<<" ";
        if(z[i]==p.size()) occurences.push_back(i-p.size()-1);
    }
    cout<<endl;

    if(occurences.size()){
        cout<<"Pattern Found at Index: ";
        for(auto i: occurences) cout<<i<<" ";
        cout<<endl;
    }
    else cout<<"Pattern Not Found!\n";
}

/*

aabcaabc
abc

*/
