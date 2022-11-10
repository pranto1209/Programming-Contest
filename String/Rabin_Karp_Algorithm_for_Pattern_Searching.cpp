#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>occurences;
void rabin_karp(string t, string p)
{
    const int pow=31;
    const int m=1e9+9;
    ll ts=t.size(), ps=p.size();

    vector<ll>p_pow(max(ts, ps));
    p_pow[0]=1;
    for(int i=1; i<p_pow.size(); i++) p_pow[i]=(p_pow[i-1] * pow)%m;

    vector<ll>h(ts+1);
    for(int i=0; i<ts; i++) h[i+1]=(h[i] + (t[i]-'a'+1) * p_pow[i])%m;

    ll h_s=0;
    for(int i=0; i<ps; i++) h_s=(h_s + (p[i]-'a'+1) * p_pow[i])%m;

    for(int i=0; i<=ts-ps; i++){
        ll cur_h=(h[i+ps] - h[i])%m;
        if(cur_h==h_s * p_pow[i]%m) occurences.push_back(i);
    }
}
int main()
{
    string text, pattern;
    cin>>text>>pattern;

    rabin_karp(text, pattern);

    if(occurences.size()){
        cout<<"Pattern Found at Index: ";
        for(auto i: occurences) cout<<i<<" ";
        cout<<endl;
    }
    else cout<<"Pattern Not Found!\n";
}

/*

hellolllolloolo
ello

*/
