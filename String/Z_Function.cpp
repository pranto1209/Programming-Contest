#include<bits/stdc++.h>
using namespace std;
vector<int>occurences;
int z[100000];
void z_function(string s)
{
    int n=s.size();
    for(int i=1, l=0, r=0; i<n; i++){
        if(i<=r) z[i]=min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
}
int main()
{
    string s;
    cin>>s;

    z_function(s);

    for(int i=0; i<s.size(); i++) cout<<z[i]<<" ";
}

/*

aabxaabxcaabxaabxay

*/
