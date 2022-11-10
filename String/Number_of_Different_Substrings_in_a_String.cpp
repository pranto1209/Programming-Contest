#include<bits/stdc++.h>
#define ll long long
using namespace std;
int count_unique_substrings(string s)
{
    const int pow=31;
    const int m=1e9+9;
    int n=s.size(), cnt=0;

    vector<ll>p_pow(n);
    p_pow[0]=1;
    for(int i=1; i<n; i++) p_pow[i]=(p_pow[i-1] * pow)%m;

    vector<ll>h(n+1);
    for(int i=0; i<n; i++) h[i+1]=(h[i] + (s[i]-'a'+1) * p_pow[i])%m;

    for(int l=1; l<=n; l++) {
        set<ll>hs;
        for(int i=0; i<=n-l; i++){
            ll cur_h=(h[i+l] - h[i])%m;
            cur_h=(cur_h * p_pow[n-i-1])%m;
            hs.insert(cur_h);
        }
        cnt+=hs.size();
    }
    return cnt;
}
int main()
{
    string s;
    cin>>s;
    int r=count_unique_substrings(s);
    cout<<r<<endl;
}

/*

hello

*/
